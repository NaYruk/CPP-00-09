/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:07:39 by mmilliot          #+#    #+#             */
/*   Updated: 2025/09/23 15:45:04 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main (int argc, char ** argv)
{
    try {
        validateArguments(argc, argv);
        
        BitcoinExchange btc;
        btc.extract_database();
        btc.processFile(argv[1]);
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}