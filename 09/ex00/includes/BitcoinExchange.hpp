/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:07:34 by mmilliot          #+#    #+#             */
/*   Updated: 2025/09/18 15:28:34 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#define NBR_ARGS 2

#define GETLINE_ERROR "\033[31m" "\033[31m Getline failed ! \033[0m"
#define BAD_INPUT -1

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class   BitcoinExchange
{
    public:
        //CANONICAL
        BitcoinExchange();
        BitcoinExchange( BitcoinExchange & copy );
        BitcoinExchange & operator=( BitcoinExchange & copy );
        ~BitcoinExchange();

        //Function for fill the container / detected errors
        void    print_container(void);
        void    fill_container(char * Database);

    private:
        std::map<std::string, int> _DateValues;
};

void    check_validity(int argc, char ** argv);
