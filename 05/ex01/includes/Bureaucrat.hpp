/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:35:23 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/21 18:04:38 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Form.hpp"
#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
	public:
		//Canonical
		Bureaucrat( void );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( const Bureaucrat &copy );
		Bureaucrat& operator=( const Bureaucrat &copy );
		virtual ~Bureaucrat( void );
		
		//Getters
		std::string	getName( void ) const;
		int			getGrade( void ) const;
		
		// Functions for increment or decrement bureaucrat's grade :
		void	incrementGrade( void );
		void	decrementGrade( void );
		
		//Exceptions
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
		//signForm : Try to sign the Formular
		void	signForm( Form& form );
	
	private:
		const std::string name;
		int				  grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);