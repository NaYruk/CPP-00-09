/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:35:20 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/20 19:26:08 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

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