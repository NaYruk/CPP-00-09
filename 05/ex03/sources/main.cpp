/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:35:25 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/22 16:43:18 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
 	
int	main( void )
{
	{
		// SUBJECT TEST ( TEST GOOD FORM NAME : ROBOTOMY, TARGET=BENDER )
		std::cout << "TEST GOOD FORM NAME : ROBOTOMY, TARGET=BENDER" << std::endl;
		try {
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
			std::cout << *rrf << std::endl;
			
			delete rrf;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}


	{
		// TEST GOOD FORM NAME : PRESIDENTIAL, TARGET=OFFICE
		std::cout << "TEST GOOD FORM NAME : PRESIDENTIAL, TARGET=OFFICE" << std::endl;
		try {
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("Presidential Pardon", "Office");
			std::cout << *rrf << std::endl;
			
			delete rrf;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	

	{
		// TEST GOOD FORM NAME : SHRUBBERY, TARGET=GARDEN
		std::cout << "TEST GOOD FORM NAME : SHRUBBERY, TARGET=GARDEN" << std::endl;
		try {
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("Shrubbery Creation", "Garden");
			std::cout << *rrf << std::endl;
			
			delete rrf;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	

	{
		// TEST FALSE FORM NAME
		std::cout << "TEST FALSE FORM NAME" << std::endl;
		try {
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("AAA", "AAA");
			std::cout << *rrf << std::endl;
			
			delete rrf;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	
	
	{
		// TEST GOOD FORM NAME AND EXECUTE : PRESIDENTIAL, TARGET=OFFICE
		std::cout << "\nTEST GOOD FORM NAME AND EXECUTE : PRESIDENTIAL, TARGET=OFFICE" << std::endl;
		try {
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("Presidential Pardon", "Office");
			std::cout << *rrf << std::endl;
			
			Bureaucrat test("test", 1);
			test.signForm(*rrf);
			rrf->execute( test );
			
			delete rrf;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}