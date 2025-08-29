/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:54:42 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/29 16:03:02 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

//Canonical
ScalarConverter::ScalarConverter( void ) {}	

ScalarConverter::ScalarConverter( ScalarConverter& copy ) { (void)copy; }

ScalarConverter&	ScalarConverter::operator=( ScalarConverter& copy )
{
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter( void ) {}










//Enum for differentiate the variables type in the string
enum Types
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	UNKNOWN_TYPE
};



// ScalarValues contain all utility variables
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

	bool	NonDisplayableChar;
	
	bool	except;
};

bool	pseudoLiterals( std::string const literal )
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << RED << "char: impossible" << RESET << std::endl;
		std::cout << RED << "int: impossible" << RESET << std::endl;
		std::cout << RED << "float: nanf" << RESET << std::endl;
		std::cout << RED << "double: nan" << RESET << std::endl;
		return true;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << RED << "char: impossible" << RESET << std::endl;
		std::cout << RED << "int: impossible" << RESET << std::endl;
		std::cout << RED << "float: -inff" << RESET << std::endl;
		std::cout << RED << "double: -inf" << RESET << std::endl;
		return true;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << RED << "char: impossible" << RESET << std::endl;
		std::cout << RED << "int: impossible" << RESET << std::endl;
		std::cout << RED << "float: +inff" << RESET << std::endl;
		std::cout << RED << "double: +inf" << RESET << std::endl;
		return true;
	}
	return false;
}

// Function for parse the string and detected the type of variable, if none type is detected return UNKNOW TYPE.
static Types	detectType( std::string const & literal, bool	*DecimalDetected)
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
			{
				*DecimalDetected = true;
				nbPoints++;
			}
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



// Function for convert the variables in the 3 others type, and Detected Overflow, Underflow, or the impossibility to print the variable after the cast
static ScalarValues	parse_litteral( Types type, std::string literal )
{
	ScalarValues	Values;
	
	Values.NonDisplayableChar = false;
	Values.impossibleChar = false;
	Values.impossibleDouble = false;
	Values.impossibleFloat = false;
	Values.impossibleInt = false;
	Values.except = false;
	
	char	* pEnd = NULL;
	errno = 0;

	// Convert in the original type of literal string and convert to the 3 other types.
	try {
		switch ( type )
		{
			case TYPE_CHAR:
			{
				// A char will always fit in an int, double, or float so no check needed here!
				Values.c = literal[0];
				Values.d = static_cast<double>(Values.c);
				Values.i = static_cast<int>(Values.c);
				Values.f = static_cast<float>(Values.c);
				break;
			}
			case TYPE_INT:
			{
				// Check for overflow, if the entered Int is too large!
				long int	nbr = std::strtol(literal.c_str(), &pEnd, 10);
				if (errno == ERANGE || pEnd == literal.c_str())
					throw std::out_of_range("Overflow detected !");
				
				if (nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
					throw std::out_of_range("Overflow detected !");
				
				Values.i = static_cast<int>(nbr);

				// Check if the int is printable as a character, if it is not part of the ascii table, write impossible, otherwise Non displayable!
				if (Values.i < 0 || Values.i > 177)
					Values.impossibleChar = true;
				else if (!std::isprint(Values.i))
					Values.NonDisplayableChar = true;
				else
					Values.c = static_cast<char>(Values.i);
					
				// An int always fits in a float or double so no particular check needed.
				Values.d = static_cast<double>(Values.i);
				Values.f = static_cast<float>(Values.i);
				break;
			}
			case TYPE_FLOAT:
			{
				// Check for overflow, if the entered Float is too large!
				Values.f = std::strtof(literal.c_str(), &pEnd);
				if (errno == ERANGE || pEnd == literal.c_str())
					throw std::out_of_range("Overflow detected !");
				

				// Check if the float is printable as a character, if it is not part of the ascii table, write impossible, otherwise Non displayable!
				if (Values.f < 0 || Values.f > 177)
					Values.impossibleChar = true;
				else if (!std::isprint(Values.f))
					Values.NonDisplayableChar = true;
				else
					Values.c = static_cast<char>(Values.f);
				

				// Check if the float fits in an Int, otherwise say that displaying the Int is impossible!
				pEnd = NULL;
				Values.d = std::strtod(literal.c_str(), &pEnd);
				if (errno == ERANGE || pEnd == literal.c_str())
					throw std::out_of_range("Overflow detected !");
				
				if (Values.d < std::numeric_limits<int>::min() || Values.d > std::numeric_limits<int>::max())
					Values.impossibleInt = true;
				else
					Values.i = static_cast<int>(Values.d);


				// A float always fits in a double so no worries about the cast!
				Values.d = static_cast<double>(Values.f);
				break;
			}
			case TYPE_DOUBLE:
			{
				// Check for overflow, if the entered Double is too large!
				Values.d = std::strtod(literal.c_str(), &pEnd);
				if (errno == ERANGE || pEnd == literal.c_str())
					throw std::out_of_range("Overflow detected !");


				// Check if the double is printable as a character, if it is not part of the ascii table, write impossible, otherwise Non displayable!
				if (Values.d < 0 || Values.d > 177)
					Values.impossibleChar = true;
				else if (!std::isprint(Values.d))
					Values.NonDisplayableChar = true;
				else
					Values.c = static_cast<char>(Values.d);

				// Check if the double fits in an Int, otherwise say that displaying the Int is impossible!
				if (Values.d < std::numeric_limits<int>::min() || Values.d > std::numeric_limits<int>::max())
					Values.impossibleInt = true;
				else
					Values.i = static_cast<int>(Values.d);


				// Check if the double fits in a Float, otherwise say that displaying the Float is impossible!
				if (Values.d > std::numeric_limits<float>::max() || Values.d < -std::numeric_limits<float>::max())
					Values.impossibleFloat = true;
				else
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


static bool	IsScientistConversion( std::string literal )
{
	int	index = 0;
	for ( int i = index; literal[i] == '0' || literal[i] == '+' || literal[i] == '-'; i++ ) { index++; }

	int count = 0;
	while ( literal[index] != '\0' && literal[index] != '.' )
	{
		count++;
		index++;
	}
	if ( count > 6 )
		return true;
	else
		return false;
}


// Function for print the Variables
static void	printValues( ScalarValues Values, bool DecimalDetected, std::string literal )
{
	// If Exception thrown, do nothing
	if (Values.except == true)
		return ;
	
	// Print Char
	if (Values.impossibleChar == false && Values.NonDisplayableChar == false)
		std::cout << "char: " << Values.c << std::endl;
	else if (Values.NonDisplayableChar == true)
		std::cout << RED << "char: Non displayable" << RESET << std::endl;
	else
		std::cout << RED << "char: impossible" << RESET << std::endl;
	

	//Print Int
	if (Values.impossibleInt == false)
		std::cout << "int: " << Values.i << std::endl;
	else
		std::cout << RED << "int: impossible" << RESET << std::endl;


	// Print Float
	if (Values.impossibleFloat == false)
	{
		if (DecimalDetected == true)
		{
			if (roundf(Values.f) == Values.f && !IsScientistConversion(literal))
				std::cout << "float: " << Values.f << ".0f" << std::endl;
			else
				std::cout << "float: " << Values.f << "f" << std::endl;
		}
		else if (!IsScientistConversion(literal))
			std::cout << "float: " << Values.f << ".0f" << std::endl;
		else
			std::cout << "float: " << Values.f << "f" << std::endl;
	}
	else
	    std::cout << RED << "float: impossible" << RESET << std::endl;
	
		
	// Print Double
	if (Values.impossibleDouble == false)
	{
		if (DecimalDetected == true)
		{
			if (roundf(Values.d) == Values.d && !IsScientistConversion(literal))
				std::cout << "double: " << Values.f << ".0" << std::endl;
			else
				std::cout << "double: " << Values.f << std::endl;
		}
		else if (!IsScientistConversion(literal))
			std::cout << "double: " << Values.f << ".0" << std::endl;
		else
			std::cout << "double: " << Values.f << std::endl;
	}
	else
		std::cout << RED << "double: impossible" << RESET << std::endl;
}

// Main function for convert the string and do the 4 convertions
void	ScalarConverter::convert( std::string const & literal )
{
	bool	DecimalDetected = false;

	if (literal.empty()) {
		std::cerr << RED << "The Argument is empty !" << RESET << std::endl;
		return ;
	}
	
	ScalarValues Values;

	if (!pseudoLiterals( literal ))
	{
		Types type = detectType( literal, &DecimalDetected);
		
		Values = parse_litteral( type, literal );

		printValues( Values, DecimalDetected, literal );
	}
	
	return ;
}