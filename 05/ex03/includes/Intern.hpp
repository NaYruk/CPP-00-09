/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:34:49 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/22 14:39:05 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Bureaucrat.hpp"

class	Intern
{
	public:
		//CANONICAL
		Intern( void );
		Intern( const Intern& copy );
		Intern& operator=( const Intern& copy );
		~Intern( void );
		
		//Exception
		class	InvalidFormException : public std::exception
		{
			virtual const char* what() const throw();
		};

		//makeForm : Create a form with the good target
		AForm*	makeForm( std::string forName, std::string target );
};