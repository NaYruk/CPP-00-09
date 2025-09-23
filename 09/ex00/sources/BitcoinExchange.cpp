/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:07:36 by mmilliot          #+#    #+#             */
/*   Updated: 2025/09/23 22:48:30 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

// ============== CANONICAL =================
BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange &copy)
{
    *this = copy;
    return;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &copy)
{
    this->_Database = copy._Database;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

// ================= PUBLIC INTERFACE ====================
void BitcoinExchange::extract_database(void)
{
    std::string line;
    std::ifstream ifs;

    ifs.open("data.csv", std::ios::in);
    if (ifs.is_open() == false)
        throw std::runtime_error(RED "❌ The Database in : ../data.csv can't be open ❌" RESET);
    std::getline(ifs, line); // skip first line
    while (std::getline(ifs, line))
    {
        std::string date = line.substr(DATE_IN_DATABASE, SIZE_OF_DATE);
        std::string valueSTR = line.substr(VALUE_IN_DATABASE, line.length() - VALUE_IN_DATABASE);
        std::istringstream iss(valueSTR);
        float value;
        if (iss >> value)
        {
            this->_Database.insert(std::make_pair(date, value));
        }
    }
    return;
}

void BitcoinExchange::processFile(const char *filename)
{
    std::ifstream ifs;
    _openFile(filename, ifs);

    std::string line;
    std::getline(ifs, line); // Ignore the first line (date | value)
    while (std::getline(ifs, line))
    {
        if (line.empty() == false)
            _CheckLineAndDoExchange(line);
    }
    ifs.close();
    return;
}

// ==================== PRIVATE METHODS ==========================
void BitcoinExchange::_openFile(const char *filename, std::ifstream &ifs)
{
    ifs.open(filename, std::ios::in);
    if (ifs.is_open() == false)
        throw std::runtime_error(RED "❌ The file: " + std::string(filename) + " can't be open ❌" RESET);
    return;
}

void BitcoinExchange::_CheckLineAndDoExchange(std::string &line)
{
    if (line.length() < MINIMUM_LENGTH_STR)
    {
        _displayError(BAD_INPUT, line);
        return;
    }

    // Check the separator : " | "
    std::string separator = line.substr(SEPARATOR_IN_STR, SIZE_OF_SEPARATOR);
    if (separator != " | ")
    {
        _displayError(BAD_INPUT, line);
        return;
    }

    // Extract Date and value
    std::string date = line.substr(DATE_IN_STR, SIZE_OF_DATE);
    std::string valueSTR = line.substr(VALUE_IN_STR, line.length() - VALUE_IN_STR);

    // Validity of the date
    if (_isValidDate(date) == false)
    {
        _displayError(BAD_INPUT, line);
        return;
    }

    float value;
    if (_isValidValue(valueSTR, value) == false)
    {
        _displayError(BAD_INPUT, line);
        return;
    }

    // Check limits
    if (value < VALUE_MIN_LIMIT)
    {
        _displayError(NEGATIVE_VALUE, line);
        return;
    }
    else if (value > VALUE_MAX_LIMIT)
    {
        _displayError(TOO_LARGE_NUMBER, line);
        return;
    }

    // Calculate and find the closest date if the date is not found in the database
    std::string closestDate = _findClosestDate(date);
    float exchangeRate = _getExchangeRate(closestDate);

    // Print the result
    float result = value * exchangeRate;
    std::cout << date << " => " << value << " = " << result << std::endl;
    return;
}

bool BitcoinExchange::_isValidDate(std::string &date) const
{
    // Check the lenght
    if (date.length() != SIZE_OF_DATE)
        return false;

    // Check the format AAAA-MM-JJ
    if (date[FIRST_DASH_POS] != '-' || date[SECOND_DASH_POS] != '-')
        return false;

    // Check digit
    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == FIRST_DASH_POS || i == SECOND_DASH_POS)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    std::string yearsSTR = date.substr(YEAR_IN_DATE_STR, 4);  // AAAA
    std::string monthSTR = date.substr(MONTH_IN_DATE_STR, 2); // MM
    std::string daysSTR = date.substr(DAY_IN_DATE_STR, 2);    // DD

    int years = std::atoi(yearsSTR.c_str());
    int month = std::atoi(monthSTR.c_str());
    int days = std::atoi(daysSTR.c_str());

    if (years < MIN_YEAR || years > MAX_YEAR)
        return false;
    if (month < MIN_MONTH || month > MAX_MONTH)
        return false;
    if (days < MIN_DAY || days > MAX_DAY)
        return false;

    // Array for check the max days in each month
    int DaysInNormalYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check leap year (year must be divisible by 4 BUT if is also divisible by 100 it is not a leap year, HOWEVER if it is divisible by 400 it is a leap year)
    if (month == FEBRUARY && ((years % DIVISIBLE_BY_4 == 0 && years % DIVISIBLE_BY_100 != 0) || (years % DIVISIBLE_BY_400 == 0)))
        DaysInNormalYear[1] = DAYS_IN_FEBRUARY_LEAP;

    // Check if the nbr of days is OK compare to the DaysInNormalYear Array
    if (days > DaysInNormalYear[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::_isValidValue(const std::string &valueStr, float &value) const
{
    if (valueStr.empty())
        return false;

    // Basic validation
    bool hasPoint = false;
    for (size_t i = 0; i < valueStr.length(); i++)
    {
        char c = valueStr[i];
        if (c == '.')
        {
            if (hasPoint == true)
                return false;
            hasPoint = true;
        }
        else if (c == '-' && i == 0)
            continue;
        else if (!std::isdigit(c))
            return false;
    }

    // Convertion
    std::istringstream iss(valueStr);
    iss >> value;

    return true;
}

std::string BitcoinExchange::_findClosestDate(const std::string &date) const
{
    // Find the exact date
    std::map<std::string, float>::const_iterator it = this->_Database.find(date);
    if (it != this->_Database.end())
        return it->first;

    // If the date is not found find the closest
    it = this->_Database.lower_bound(date);

    if (it == this->_Database.end())
    {
        --it;
        return it->first; // If all date is < in the DB choose the last one
    }

    if (it == this->_Database.begin())
        return this->_Database.begin()->first; // If all date is > in the DB choose the first one

    --it; // Choose the closest and lowest date
    return it->first;
}

float BitcoinExchange::_getExchangeRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = this->_Database.find(date);
    return it->second;
}

void BitcoinExchange::_displayError(const int type, const std::string &line) const
{
    if (type == BAD_INPUT)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
    }
    else if (type == NEGATIVE_VALUE)
    {
        std::cerr << "Error: not a positive number." << std::endl;
    }
    else if (type == TOO_LARGE_NUMBER)
    {
        std::cerr << "Error: too large number." << std::endl;
    }
    return;
}

// ===================== GLOBALS METHODS =========================
void validateArguments(int argc, char **argv)
{
    std::string line;

    // Check if the file in argument is absent
    if (argc != NBR_ARGS)
    {
        throw std::runtime_error(RED "❌ The program needs 1 argument (a file)! ❌" RESET);
    }

    // Check if the file is openable
    std::ifstream ifs;
    ifs.open(argv[1], std::ios::in);
    if (ifs.is_open() == false)
        throw std::runtime_error(RED "❌ The file: " + std::string(argv[1]) + " can't be open ❌" RESET);

    if (std::getline(ifs, line))
    {
        if (line != "date | value")
            throw std::runtime_error(RED "❌ The first line of the Database is not : date | value ❌" RESET);
    }
    else
        throw std::runtime_error(GETLINE_ERROR);
    ifs.close();

    return;
}
