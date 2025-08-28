/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:32:08 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/28 21:31:31 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main( int argc, char **argv )
{
	if ( argc != 2 ) {
		std::cerr << "Error, bad Number of Arguments !" << std::endl;
		return 1;
	}
	
	ScalarConverter::convert( std::string(argv[1]) );

	return 0;
}



// Some test for the correction : 

/*
	Overflow Int : 2147483648, -2147483649

	Overflow Float : 340282400000000000000000000000000000000.0f; (delete one 0 for not Overflow)

	Overflow Double : 1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583699.0 (Delete one nb for not Overflow)


	Char Non Displayable : 1
	Char Impossible : -1

*/