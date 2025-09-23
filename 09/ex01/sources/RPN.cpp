/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:13 by marcmilliot       #+#    #+#             */
/*   Updated: 2025/09/23 22:33:27 by mmilliot         ###   ########.fr       */
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
	char * token = std::strtok(str, " ");
	if (!token)
		throw std::runtime_error(RED "Strtok failed : Bad Input" RESET);
	
	while (token != NULL) {
		if (_isValidToken(token) == false) {
			std::cerr << RED "Syntax Error !" RESET << std::endl;
			return ;
		}
		
		int	TypeToken = _getTypeToken(token);
		switch (TypeToken)
		{
			case IS_DIGIT:
				this->_NbrStack.push(std::atoi(token));
				break;
			case IS_DIVIDE:
			case IS_MINUS:
			case IS_MULT:
			case IS_PLUS:
			{
				if (this->_NbrStack.size() < NBR_FOR_APPLY_OPERATOR) {
					std::cerr << RED "Syntax Error : Need 2 Nbr in the stack for apply an operation." << RESET << std::endl;
					return ;
				}
				int firstNbr = this->_NbrStack.top();
				this->_NbrStack.pop();
				int secondNbr = this->_NbrStack.top();
				this->_NbrStack.pop();
				if (_doOperation(firstNbr, secondNbr, TypeToken) == -1)
					return ;
				break;
			}
			default:
				break;
		}
		token = std::strtok(NULL, " "); // NULL : Continue to split the same str at the first call
	}
	if (this->_NbrStack.size() == FINAL_STACK_SIZE) {
		std::cout << GREEN "Result : " << this->_NbrStack.top() << RESET << std::endl; 
	}
	else
		std::cerr << RED "Syntax Error : There are not enough operators to use all numbers." RESET << std::endl;
	return ;
}


// ============= PRIVATE METHODS ==============
bool	RPN::_isValidToken(std::string const token) const
{
	if (token.length() != TOKEN_SIZE) {
		return false;
	}
	if (!isdigit(token[0]) && token[0] != '+' && token[0] != '-' && token[0] != '/' && token[0] != '*') {
		return false;
	}
	return true;
}

int		RPN::_getTypeToken(std::string const token) const
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

int		RPN::_doOperation(int firstNbr, int secondNbr, int TypeToken)
{
	int result;
	
	switch (TypeToken)
	{
		case IS_PLUS:
			result = secondNbr + firstNbr;
			break;
		case IS_MINUS:
			result = secondNbr - firstNbr;
			break;
		case IS_MULT:
			result = secondNbr * firstNbr;
			break;
		case IS_DIVIDE:
			if (firstNbr == DIVIDE_BY_ZERO) {
				std::cerr << RED "Division by zero" RESET << std::endl;
				return -1;
			}
			result = secondNbr / firstNbr;
			break;
			 
		default:
			std::cerr << RED "The token is not an operand (BIG CRASH)" RESET << std::endl;
			return -1;
	}
	this->_NbrStack.push(result);
	return 0;
}