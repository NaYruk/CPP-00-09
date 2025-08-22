/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:53:18 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/22 16:25:15 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

//Canonical
ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Shrubbery", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("Shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) : AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()), target(copy.target) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& copy )
{
	if (this != &copy)
	{
		this->target = copy.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}




//makeAction : Execute the action of Shrubbery
//Execute : Execute the method of AForm

void	ShrubberyCreationForm::makeAction( void ) const
{
	std::ofstream file_out(this->target + "_shrubbery", std::ios::out);
	if (file_out.is_open() == false) {
		std::cerr << "Error: Could not open file for writing." << std::endl;
        return;
	}
	file_out << 
	"               \\/ |    |/ \n"
	"        \\/ / \\||/  /_/___/_ \n"
	"         \\/   |\\/ \n"
	"    _\\__\\_\\   |  /_____/__ \n"
	"           \\  | /          / \n"
	"  __ _-----`  |{,-----------~ \n"
	"            \\ }{ \n"
	"             }{{ \n"
	"             }}{ \n"
	"             {{}} \n"
	"       , -=-~{ .-^- _ \n"
	"  ejm        `} \n"
	"              { \n"
	<< std::endl;
	return ;

}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
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