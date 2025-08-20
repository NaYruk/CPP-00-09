/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:25:03 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/20 19:19:34 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Bureaucrat.hpp"

class Form
{
	public:
		//Canonical
		Form( void );
		Form( std::string name, int gradeForSign, int gradeForExec);
		Form( const Form& copy );
		Form& operator=( const Form& copy );
		~Form( void );
	
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
		
		//beSigned : Changes the form’s status to signed if the bureaucrat’s grade is high enough
		void	beSigned( const Bureaucrat& b ) const;
	
	private:
		const std::string _name;
		bool			  _isSigned;
		const int		  _gradeForSign;
		const int		  _gradeForExec;

};

std::ostream&	operator<<( std::ostream& os, Form& form );