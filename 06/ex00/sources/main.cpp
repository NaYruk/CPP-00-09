/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:32:08 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/25 20:39:27 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main( int argc, char **argv )
{
	if ( argc != 2 ) {
		std::cerr << "Error, bad Number of Arguments !" << std::endl;
		return 1;
	}
	
	ScalarConverter::convert( argv[1] );

	return 0;
}