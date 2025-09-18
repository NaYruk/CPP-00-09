/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:07:39 by mmilliot          #+#    #+#             */
/*   Updated: 2025/09/18 11:47:04 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main (int argc, char ** argv)
{
    try {
        check_validity(argc, argv);
        
        BitcoinExchange btc;
        btc.fill_container(argv[1]);
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}