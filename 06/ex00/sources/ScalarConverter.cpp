/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:54:42 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/26 11:40:19 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

ScalarConverter::ScalarConverter( void ) {}	

ScalarConverter::ScalarConverter( ScalarConverter& copy ) { (void)copy; }

ScalarConverter&	ScalarConverter::operator=( ScalarConverter& copy )
{
	(void)copy;
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

struct	ScalarValues
{
	int		i;
	char	c;
	float	f;
	double	d;
	
	bool	impossibleInt;
	bool	impossibleChar;
	bool	impossibleFloat;
	bool	impossibleDouble;
	
	bool	except;
};

static Types	detectType( std::string const & literal )
{
	if ( literal.length() == 1 && !isdigit(literal[0]) )
		return TYPE_CHAR;
		
	else
	{
		int		nbSign = 0;
		int		nbF = 0;
		int		nbPoints = 0;

		for (int i = 0; i < static_cast<int>(literal.length()); i++) {
			if (!isdigit(literal[i]) && literal[i] != '+' && literal[i] != '-' && literal[i] != '.' && literal[i] != 'f')
				return UNKNOWN_TYPE;
			if (literal[i] == '+' || literal[i] == '-')
				nbSign++;
			if (literal[i] == '.')
				nbPoints++;
			if (literal[i] == 'f')
				nbF++;
		}
		if (nbSign > 1 || nbPoints > 1 || nbF > 1)
			return UNKNOWN_TYPE;
		if (nbSign == 1 && literal[0] != '+' && literal[0] != '-')
			return UNKNOWN_TYPE;
		if (nbF == 1 && literal[literal.length() - 1] != 'f')
			return UNKNOWN_TYPE;
		if (nbPoints == 1 && literal[literal.length() - 1] == '.')
			return UNKNOWN_TYPE;
		if (nbPoints == 1 && literal[0] == '.')
			return UNKNOWN_TYPE;
			
		if (nbF == 1)
			return TYPE_FLOAT;
		else if (nbPoints == 1)
			return TYPE_DOUBLE;
		else
			return TYPE_INT;
	}
	
	return UNKNOWN_TYPE;
}

// Check le nombre de +, -, f, . dans la string
//check si le + et - est au debut
//check si le f est a la fin

static ScalarValues	parse_litteral( Types type, std::string literal )
{
	ScalarValues	Values;
	
	Values.impossibleChar = false;
	Values.impossibleDouble = false;
	Values.impossibleFloat = false;
	Values.impossibleInt = false;
	Values.except = false;
	
	// Convert in the origin type of literal string and convert in the 3 other type.
	try {
		switch ( type )
		{
			case TYPE_CHAR:
			{
				Values.c = literal[0];
				Values.d = static_cast<double>(Values.c);
				Values.i = static_cast<int>(Values.c);
				Values.f = static_cast<float>(Values.c);
				break;
			}
			case TYPE_INT:
			{
				std::stringstream ss(literal);

				ss >> Values.i;
				if (Values.i < 32 || Values.i > 127)
					Values.impossibleChar = true;
				else
					Values.c = static_cast<char>(Values.i);
					
				Values.d = static_cast<double>(Values.i);
				Values.f = static_cast<float>(Values.i);
				break;
			}
			case TYPE_FLOAT:
			{
				std::stringstream ss(literal);

				ss >> Values.f;
				if (Values.f < 32 || Values.f > 127)
					Values.impossibleChar = true;
				else
					Values.c = static_cast<char>(Values.f);
					
				Values.i = static_cast<int>(Values.f);
				Values.d = static_cast<double>(Values.f);
				break;
			}
			case TYPE_DOUBLE:
			{
				std::stringstream ss(literal);
				
				ss >> Values.d;
				if (Values.d < 32 || Values.d > 127)
					Values.impossibleChar = true;
				else
					Values.c = static_cast<char>(Values.d);
					
				Values.i = static_cast<int>(Values.d);
				Values.f = static_cast<float>(Values.d);
				break;
			}
			default:
				throw	std::invalid_argument("Unknown Type !");
		};
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		
		Values.except = true;
		return Values;
	}
	
	return Values;
}

static void	printValues( ScalarValues Values )
{
	if (Values.except == true)
		return ;
		
	if (Values.impossibleChar == false)
		std::cout << "char: " << Values.c << std::endl;
	else
		std::cout << RED << "char : Non displayable" << RESET << std::endl;
	
	if (Values.impossibleInt == false)
		std::cout << "int: " << Values.i << std::endl;
	else
		std::cout << RED << "int: impossible" << RESET << std::endl;

	if (Values.impossibleFloat == false)
		std::cout << "float: " << Values.f << std::endl;
	else
		std::cout << RED << "float: impossible" << RESET << std::endl;
	
	if (Values.impossibleDouble == false)
		std::cout << "double: " << Values.d << std::endl;
	else
		std::cout << RED << "double: impossible" << RESET << std::endl;
}

void	ScalarConverter::convert( std::string const & literal )
{
	if (literal.empty()) {
		std::cerr << RED << "The Argument is empty !" << RESET << std::endl;
		return ;
	}
	
	Types type = detectType( literal );
	
	ScalarValues Values = parse_litteral( type, literal );

	printValues( Values );
	
	return ;
}