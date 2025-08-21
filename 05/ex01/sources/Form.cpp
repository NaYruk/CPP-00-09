/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:25:00 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/21 18:52:25 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
	
//CANONICAL
Form::Form( void ) : _name("Default"), _isSigned(false), _gradeForSign(150), _gradeForExec(150) {}

Form::Form( std::string name, int gradeForSign, int gradeForExec) : _name(name), _isSigned(false), _gradeForSign(gradeForSign), _gradeForExec(gradeForExec)
{
	if (gradeForSign > 150 || gradeForExec > 150)
		throw GradeTooLowException();
	else if (gradeForSign < 1 || gradeForExec < 1)
		throw GradeTooHighException();
	return ;
}

Form::Form( const Form& copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeForSign(copy._gradeForSign), _gradeForExec(copy._gradeForExec) {}

Form&	Form::operator=( const Form& copy )
{
	// name, gradeForSign, gradeForExec are const attributes, can't modify them.
	if (this != &copy)
	{
		this->_isSigned = copy._isSigned;
	}
	return *this;
}

Form::~Form( void ) {}




//GETTERS
std::string	Form::getName( void ) const
{
	return this->_name;
}

int	Form::getGradeSign( void ) const
{
	return this->_gradeForSign;
}

int	Form::getGradeExec( void ) const
{
	return this->_gradeForExec;
}

bool	Form::getIsSigned( void ) const
{
	return this->_isSigned;
}




//EXCEPTIONS
const char* Form::GradeTooHighException::what() const throw() 
{
	return (RED "The grade is Too High !!!! [1 ; 150] | 1 is the Highest !!!" RESET);
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return (RED "The grade is Too Low !!!! [1 ; 150] | 150 is the Lowest !!!" RESET);
}




//beSigned : Changes the form’s status to signed if the bureaucrat’s grade is high enough
void	Form::beSigned( const Bureaucrat& b )
{
	
	if (this->_gradeForSign < b.getGrade())
		throw GradeTooLowException();
		
	if (this->_isSigned == true) // Test Signed Status before signed !
		std::cout << GREEN << "The Formular is already signed !" << RESET << std::endl;
	else
		this->_isSigned = true;
	return ;
}



//Overload of << operator
std::ostream&	operator<<( std::ostream& os, Form& form )
{
	os << "Form : " << form.getName() << "\nStatus : " << form.getIsSigned() << "\nGrade for exec : " << form.getGradeExec() << "\nGrade for sign : " << form.getGradeSign() << std::endl;
	
	return os;
}