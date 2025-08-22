/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:25:00 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/21 19:26:54 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
	
//CANONICAL
AForm::AForm( void ) : _name("Default"), _isSigned(false), _gradeForSign(150), _gradeForExec(150) {}

AForm::AForm( std::string name, int gradeForSign, int gradeForExec) : _name(name), _isSigned(false), _gradeForSign(gradeForSign), _gradeForExec(gradeForExec)
{
	if (gradeForSign > 150 || gradeForExec > 150)
		throw GradeTooLowException();
	else if (gradeForSign < 1 || gradeForExec < 1)
		throw GradeTooHighException();
	return ;
}

AForm::AForm( const AForm& copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeForSign(copy._gradeForSign), _gradeForExec(copy._gradeForExec) {}

AForm&	AForm::operator=( const AForm& copy )
{
	// name, gradeForSign, gradeForExec are const attributes, can't modify them.
	if (this != &copy)
	{
		this->_isSigned = copy._isSigned;
	}
	return *this;
}

AForm::~AForm( void ) {}




//GETTERS
std::string	AForm::getName( void ) const
{
	return this->_name;
}

int	AForm::getGradeSign( void ) const
{
	return this->_gradeForSign;
}

int	AForm::getGradeExec( void ) const
{
	return this->_gradeForExec;
}

bool	AForm::getIsSigned( void ) const
{
	return this->_isSigned;
}




//EXCEPTIONS
const char* AForm::GradeTooHighException::what() const throw() 
{
	return (RED "The grade is Too High !!!! [1 ; 150] | 1 is the Highest !!!" RESET);
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return (RED "The grade is Too Low !!!! [1 ; 150] | 150 is the Lowest !!!" RESET);
}

const char*	AForm::FormNotSigned::what() const throw()
{
	return (RED "You cant't execute, the Form is not Signed !" RESET);
}

const char* AForm::NotAllowed::what() const throw()
{
	return (RED "You cant't execute, the Bureaucrat is not Allowed !" RESET);
}




//beSigned : Changes the AForm’s status to signed if the bureaucrat’s grade is high enough
void	AForm::beSigned( const Bureaucrat& b )
{
	
	if (this->_gradeForSign < b.getGrade())
		throw GradeTooLowException();
		
	if (this->_isSigned == true) // Test Signed Status before signed !
		std::cout << GREEN << "The Formular is already signed !" << RESET << std::endl;
	else
		this->_isSigned = true;
	return ;
}


// Execute :
void	AForm::execute( Bureaucrat const & executor ) const
{
	if (this->getIsSigned() == false)
		throw FormNotSigned();
	else if (this->_gradeForExec < executor.getGrade())
		throw NotAllowed();
	else
		makeAction();
	return ;
}


//Overload of << operator
std::ostream&	operator<<( std::ostream& os, AForm& AForm )
{
	if (AForm.getIsSigned() == true)
	{
		os << "AForm : " << AForm.getName() << "\nStatus : True" << "\nGrade for exec : " << AForm.getGradeExec() << "\nGrade for sign : " << AForm.getGradeSign() << std::endl;
	}
	else
	{
		os << "AForm : " << AForm.getName() << "\nStatus : False" << "\nGrade for exec : " << AForm.getGradeExec() << "\nGrade for sign : " << AForm.getGradeSign() << std::endl;
	}
	
	return os;
}