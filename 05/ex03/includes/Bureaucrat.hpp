/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:35:23 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/22 16:24:32 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./AForm.hpp"
#include <iostream>
#include <exception>

class AForm;

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
		void	signForm( AForm& form );
	
	private:
		const std::string name;
		int				  grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);