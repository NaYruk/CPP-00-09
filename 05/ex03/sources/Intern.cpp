/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:47:57 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/22 15:52:29 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

//CANONICAL
Intern::Intern( void ) {}

Intern::Intern( const Intern& copy ) {}

Intern&	Intern::operator=( const Intern& copy )
{
	return *this;
}

Intern::~Intern( void ) {}



//Exception
const char*	Intern::InvalidFormException::what() const throw()
{
	return (RED "Invalid form name ! We have : Robotomy Request, Presidential Pardon, Shrubbery Creation" RESET);
};



//makeForm : Create a form with the good target
AForm*	Intern::makeForm( std::string forName, std::string target )
{
	std::string	tab[] = {"Robotomy Request", "Presidential Pardon", "Shrubbery Creation"};
	
	int	index = -1;
	for(int i = 0; i < 3; i++)
	{
		if (tab[i].compare(forName) == 0)
		{
			index = i;
			break ;
		}
	}
	
	switch ( index )
	{
		case 0:
			std::cout << GREEN << "Intern creates Robotomy Request" << RESET << std::endl;
			return (new RobotomyRequestForm(target));
			
		case 1:
			std::cout << GREEN << "Intern creates Presidential Pardon" << RESET << std::endl;
			return (new PresidentialPardonForm(target));
			
		case 2:
			std::cout << GREEN <<  "Intern creates Shrubbery Creation" << RESET << std::endl;
			return (new ShrubberyCreationForm(target));
	
		default:
			throw Intern::InvalidFormException();
	}
	return (NULL);
}