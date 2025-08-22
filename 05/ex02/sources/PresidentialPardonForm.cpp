/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:27:20 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/22 16:14:34 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

//CANONICAL
PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Presidential", 25, 5), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("Presidential", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ) : AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()), target(copy.target) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& copy )
{
	if (this != &copy)
	{
		this->target = copy.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}





//makeAction : Execute the action of Shrubbery
//Execute : Execute the method of AForm
void	PresidentialPardonForm::makeAction( void ) const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox !" << std::endl;
	return ;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
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