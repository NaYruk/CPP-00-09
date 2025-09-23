/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:09 by marcmilliot       #+#    #+#             */
/*   Updated: 2025/09/23 18:31:12 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#define NBR_ARGUMENTS 2
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
		void	_doOperation(int firstNbr, int secondNbr, int TypeToken);
};



// push les tokens nombres
// quand un token operateur est detecter, top
// 2 token nombre et faire l operation puis push
// le resultat.
// Faire l'operation jusqu a la fin.