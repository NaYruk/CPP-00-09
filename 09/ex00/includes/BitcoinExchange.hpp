/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:07:34 by mmilliot          #+#    #+#             */
/*   Updated: 2025/09/23 22:47:16 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// ========= MACRO FOR MAGIC NUMBERS ============
#define NBR_ARGS 2
#define BAD_INPUT -1
#define TOO_LARGE_NUMBER -2
#define NEGATIVE_VALUE -3
#define DATE_IN_DATABASE 0
#define SIZE_OF_DATE 10
#define VALUE_IN_DATABASE 11
#define MINIMUM_LENGTH_STR 14
#define SEPARATOR_IN_STR 10
#define SIZE_OF_SEPARATOR 3
#define DATE_IN_STR 0
#define VALUE_IN_STR 13
#define VALUE_MIN_LIMIT 0
#define VALUE_MAX_LIMIT 1000
#define YEAR_IN_DATE_STR 0
#define MONTH_IN_DATE_STR 5
#define DAY_IN_DATE_STR 8
#define MIN_YEAR 1000
#define MAX_YEAR 9999
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_DAY 1
#define MAX_DAY 31
#define FIRST_DASH_POS 4
#define SECOND_DASH_POS 7
#define FEBRUARY 2
#define DAYS_IN_FEBRUARY_LEAP 29
#define DIVISIBLE_BY_4 4
#define DIVISIBLE_BY_100 100
#define DIVISIBLE_BY_400 400

// ========= MACROS ERROR ===========
#define GETLINE_ERROR "\033[31m" \
                      "\033[31m Getline failed ! \033[0m"

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>

class BitcoinExchange
{
public:
    // ============== CANONICAL =================
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange &copy);
    BitcoinExchange &operator=(BitcoinExchange &copy);
    ~BitcoinExchange();

    // ================= PUBLIC INTERFACE ====================
    void extract_database(void);
    void processFile(const char *filename);

private:
    std::map<std::string, float> _Database;

    // ==================== PRIVATE METHODS ==========================
    void _openFile(const char *filename, std::ifstream &ifs);
    void _CheckLineAndDoExchange(std::string &line);
    bool _isValidDate(std::string &date) const;
    bool _isValidValue(const std::string &valueStr, float &value) const;
    std::string _findClosestDate(const std::string &date) const;
    float _getExchangeRate(const std::string &date) const;
    void _displayError(const int type, const std::string &line) const;
};

// ===================== GLOBALS METHODS =========================
void validateArguments(int argc, char **argv);