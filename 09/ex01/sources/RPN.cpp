/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:13 by marcmilliot       #+#    #+#             */
/*   Updated: 2025/09/23 18:39:40 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

// ============== CANONICAL ================
RPN::RPN( void ) {}

RPN::RPN( const RPN & copy ) {
	*this = copy;
	return ;
}

RPN & RPN::operator=( const RPN & copy ) {
	this->_NbrStack = copy._NbrStack;
	return *this;
}

RPN::~RPN( void ) {}


// ============== PUBLIC METHODS =============
void	RPN::doReversePolishNotation(char * str)
{
	// Split the str
	char * token = std::strtok(str, " ");
	if (!token)
		throw std::runtime_error(RED "Strtok failed : Bad Input" RESET);
	
	while (token != NULL) {
		if (_isValidToken(token) == false) {
			std::cerr << RED "Invalid Token : " << token << RESET << std::endl;
			return ;
		}
		
		int	TypeToken = _getTypeToken(token);
		switch (TypeToken)
		{
			case IS_DIGIT:
				this->_NbrStack.push(std::atoi(token));
			case IS_DIVIDE:
			case IS_MINUS:
			case IS_MULT:
			case IS_PLUS:
			{
				if (this->_NbrStack.size() < 2) {
					std::cerr << RED "Syntax Error : Need 2 Nbr in the stack for apply an operation : " << str << RESET << std::endl;
					return ;
				}
				int firstNbr = this->_NbrStack.top();
				this->_NbrStack.pop();
				int secondNbr = this->_NbrStack.top();
				this->_NbrStack.pop();
				_doOperation(firstNbr, secondNbr, TypeToken);
			}
			default:
				break;
		}
		token = std::strtok(NULL, " "); // NULL : Continue to split the same str at the first call
	}
	if (this->_NbrStack.size() == 1) {
		std::cout << GREEN "Result : " << this->_NbrStack.top() << RESET << std::endl; 
	}
}

// ============= PRIVATE METHODS ==============
bool	RPN::_isValidToken(std::string const token) const
{
	if (token.length() != 1) {
		return false;
	}
	if (!isdigit(token[0]) && token[0] != '+' && token[0] != '-' && token[0] != '/' && token[0] != '*') {
		return false;
	}
	return true;
}

int		RPN::_getTypeToken(std::string token) const
{
	if (isdigit(token[0]) == true)
		return IS_DIGIT;
	else if (token[0] == '+')
		return IS_PLUS;
	else if (token[0] == '-')
		return IS_MINUS;
	else if (token[0] == '/')
		return IS_DIVIDE;
	else
		return IS_MULT;
}

void	RPN::_doOperation(int firstNbr, int secondNbr, int TypeToken)
{
	int result;
	
	switch (TypeToken)
	{
		case IS_PLUS:
			result = secondNbr + firstNbr;
		case IS_MINUS:
			result = secondNbr + firstNbr;
		case IS_MULT:
			result = secondNbr + firstNbr;
		case IS_DIVIDE:
			result = secondNbr + firstNbr;
			 
		default:
			std::cerr << RED "The token is not an operand (BIG CRASH)" RESET << std::endl;
			return ;
	}
	this->_NbrStack.push(result);
	return ;
}