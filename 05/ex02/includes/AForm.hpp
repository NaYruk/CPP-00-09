/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:25:03 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/21 19:26:19 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	public:
		//Canonical
		AForm( void );
		AForm( std::string name, int gradeForSign, int gradeForExec);
		AForm( const AForm& copy );
		AForm& operator=( const AForm& copy );
		virtual ~AForm( void );
	
		//Getters
		std::string	getName( void ) const;
		int			getGradeSign( void ) const;
		int			getGradeExec( void ) const;
		bool		getIsSigned( void ) const;
	
		//Exceptions
		class	GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
		class	GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
		//beSigned : Changes the AForm’s status to signed if the bureaucrat’s grade is high enough
		void	beSigned( const Bureaucrat& b );

		// Execute : 
		virtual void	execute( Bureaucrat const & executor ) const = 0;
	
	private:
		const std::string _name;
		bool			  _isSigned;
		const int		  _gradeForSign;
		const int		  _gradeForExec;

};

//Overload of << operator
std::ostream&	operator<<( std::ostream& os, AForm& AForm );