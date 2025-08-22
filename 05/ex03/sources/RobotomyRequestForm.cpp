/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:53:19 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/22 16:25:07 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <ctime>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

//Canonical
RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("Robotomy", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("Robotomy", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ) : AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()), target(copy.target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& copy )
{
	if (this != &copy)
	{
		this->target = copy.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}



//makeAction : Execute the action of Shrubbery
//Execute : Execute the method of AForm
void	RobotomyRequestForm::makeAction( void ) const
{
	int	mod;
	std::cout << " 👨‍🔧 Brrrrrrr BRRRRRRRR brrrrrrrr BRRRRRRRR 👨‍🔧 Try to Robotomized !" << std::endl;
	
	srand((unsigned int)time(0));
	mod = rand() % 2;
	if (mod == 1)
		std::cout << GREEN << this->target << " has been succesfuly Robotomized !" << RESET << std::endl;
	else
		std::cout << RED << this->target << " Robotomy failed !" << RESET << std::endl;
	return ;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	try {
		AForm::execute( executor );
	}
	catch ( std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}