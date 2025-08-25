/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:16:44 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/25 21:41:59 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"


ScalarConverter::ScalarConverter( void ) {}	

ScalarConverter::ScalarConverter( ScalarConverter& const copy ) {}

ScalarConverter&	ScalarConverter::operator=( ScalarConverter& const copy )
{
	return *this;
}

ScalarConverter::~ScalarConverter( void ) {}







enum Types
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	UNKNOWN_TYPE
};

Types	detectType( std::string const & literal )
{
	if ( literal.length() == 1 && !isdigit(literal[0]) )
		return TYPE_CHAR;
		
	return UNKNOWN_TYPE;
}

void	convertion( Types type, std::string literal )
{
	switch ( type )
	{
		case TYPE_CHAR:
			char var = literal[0];
			break;
		case TYPE_INT:
			int	var = std::stoi( literal, 0, 10);
			break;
		case TYPE_FLOAT:
			float var = std::stof()
			break;
		case TYPE_DOUBLE:
			break;
		default:
			break;
	};
	
}

void	ScalarConverter::convert( std::string const & literal )
{
	if (literal.empty()) {
		std::cerr << "The Argument is empty !" << std::endl;
		return ;
	}
	
	convertion(detectType( literal ), literal);
	return ;
}
