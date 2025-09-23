/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:09 by marcmilliot       #+#    #+#             */
/*   Updated: 2025/09/23 22:27:33 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// ======== Macro for Magic numbers =========
#define NBR_ARGUMENTS 2
#define NBR_FOR_APPLY_OPERATOR 2
#define FINAL_STACK_SIZE 1
#define TOKEN_SIZE 1
#define DIVIDE_BY_ZERO 0


// ========= Macro for : {nbrs, +, -, /, *} =========
#define	IS_DIGIT 3
#define	IS_PLUS 4
#define IS_MINUS 5
#define IS_DIVIDE 6
#define IS_MULT 7

class RPN
{
	public:
		// ============== CANONICAL ================
		RPN( void );
		RPN( const RPN & copy );
		RPN & operator=( const RPN & copy );
		~RPN( void );

		// ============== PUBLIC METHODS =============
		void	doReversePolishNotation(char * str);
	
	private:
		std::stack<int>	_NbrStack;
		
		// ============= PRIVATE METHODS ==============
		bool	_isValidToken(std::string const token) const;
		int		_getTypeToken(std::string const token) const;
		int		_doOperation(int firstNbr, int secondNbr, int TypeToken);
};