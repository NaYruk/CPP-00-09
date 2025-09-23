/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:07:34 by mmilliot          #+#    #+#             */
/*   Updated: 2025/09/23 16:21:51 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#define NBR_ARGS 2
#define BAD_INPUT -1
#define TOO_LARGE_NUMBER -2
#define NEGATIVE_VALUE -3

#define GETLINE_ERROR "\033[31m" "\033[31m Getline failed ! \033[0m"

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>

class   BitcoinExchange
{
    public:
        // ============== CANONICAL =================
        BitcoinExchange();
        BitcoinExchange( BitcoinExchange & copy );
        BitcoinExchange & operator=( BitcoinExchange & copy );
        ~BitcoinExchange();

        // ================= PUBLIC INTERFACE ====================
        void            extract_database( void );
        void            processFile( const char * filename );
        
        private:
        std::map<std::string, float> _Database;

        // ==================== PRIVATE METHODS ==========================
        void        _openFile(const char * filename, std::ifstream & ifs);
        void        _CheckLineAndDoExchange(std::string & line);
        bool        _isValidDate(std::string & date) const;
        bool        _isValidValue(const std::string& valueStr, float& value) const;
        std::string _findClosestDate(const std::string& date) const;
        float       _getExchangeRate(const std::string& date) const;
        void        _displayError(const int type, const std::string& line) const;
 };
    
// ===================== GLOBALS METHODS =========================
void    validateArguments(int argc, char ** argv);    