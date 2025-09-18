/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:07:36 by mmilliot          #+#    #+#             */
/*   Updated: 2025/09/18 15:55:44 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/* Class BitcoinExchange Functions */
//CANONICAL
BitcoinExchange::BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange( BitcoinExchange & copy ) {
    *this = copy;
    return ;
}

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange & copy ) {
    this->_DateValues = copy._DateValues;
    return *this;
}

BitcoinExchange::~BitcoinExchange( void ) {}





static void open_file(char * Database, std::ifstream & ifs)
{
    ifs.open(Database, std::ios::in);
    if (ifs.is_open() == false)
        throw std::runtime_error(RED "❌ The file: " + std::string(Database) + " can't be open ❌" RESET);
    std::string line;
    std::getline(ifs, line); //Ignore the first line (date | value)
    return ;
}

static std::string extract_line(std::ifstream & ifs)
{
    std::string line;
    if (std::getline(ifs, line))
        return line;
    else
        throw std::runtime_error(GETLINE_ERROR);
}

void    BitcoinExchange::print_container(void)
{
    std::map<std::string, int>::iterator it = this->_DateValues.begin();
    std::map<std::string, int>::iterator end = this->_DateValues.end();

    for (; it != end; it++) {
        if (it->second == BAD_INPUT)
            std::cout << "Error: bad input => " << it->first << std::endl;
        else
            std::cout << it->first << " => " << it->second << std::endl;
    }
    return ;
}

//FILL_CONTAINER : Function for fill the container / detected errors
void    BitcoinExchange::fill_container(char * Database)
{
    std::ifstream ifs;
    open_file(Database, ifs);
    
    //std::map<std::string, int>::iterator it = this->_DateValues.begin();
    std::string line;
    std::string date;
    while (!ifs.eof())
    {
        line = extract_line(ifs);
        // FAIRE LE DECOUPAGE DE LA DATE ET DE lA VALUE DANS LE CONTAINER
        // CHECK LA DATE, SOIT A LA MAIN SOIT AVEC TM
        // CHECK LA VALUE > 1000 ET AUTRE SUPTERFUGES
        // APPLIQUER LA CONVERTION SUR LES CLE VALEURS VALIDES
        // AFFICHER LA TOTALITER
        // ATTENTION AU ANNEE BISEXTILES
    }
    print_container();
    return ;
}




/*  Functions add */
void    check_validity(int argc, char ** argv)
{
    //Check if the file in argument is absent
    if (argc != NBR_ARGS) {
        throw std::runtime_error(RED "❌ The program needs 1 argument (a file)! ❌" RESET);
    }
    
    //Check if the file is openable
    std::ifstream ifs;
    ifs.open(argv[1], std::ios::in);
    if (ifs.is_open() == false)
        throw std::runtime_error(RED "❌ The file: " + std::string(argv[1]) + " can't be open ❌" RESET);

    std::string line;
    if (std::getline(ifs, line)) {
        if (line != "date | value")
            throw std::runtime_error(RED "❌ The first line of the Database is not : date | value ❌" RESET);
    }
    else
        throw std::runtime_error(GETLINE_ERROR);

    ifs.close();
    
    return ;
}

