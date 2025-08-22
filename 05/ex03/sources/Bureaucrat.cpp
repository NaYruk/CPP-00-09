/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:35:20 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/22 11:10:14 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

Bureaucrat::Bureaucrat( void ) : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat( std::string name, int grade ) : name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->grade = grade;
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy ) : name(copy.name), grade(copy.grade) {}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& copy )
{
	// name is a const attribute, can't modify him.
	if (this != &copy)
		this->grade = copy.grade;
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {}


// Getters
std::string	Bureaucrat::getName( void ) const
{
	return (this->name);	
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->grade);
}

// Functions for increment or decrement bureaucrat's grade :
void	Bureaucrat::incrementGrade( void )
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->grade--;
	return ;
}

void	Bureaucrat::decrementGrade( void )
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->grade++;
	return ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is Too High !!!! [1 ; 150] | 1 is the Highest !!!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is Too Low !!!! [1 ; 150] | 150 is the Lowest !!!");
}


// Overload of << operator
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grad " << b.getGrade() << ".";
	
	return os;
}


//signForm : Try to sign the Formular
void	Bureaucrat::signForm( AForm& form )
{
	if (form.getIsSigned() == true)
	{
		std::cout << GREEN << "The Formular is already signed !" << RESET << std::endl; 
		return ;
	}
		
	try {
		form.beSigned(*this);
		std::cout << GREEN << this->getName() << " signed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl; 
	}
}