/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:35:25 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/21 18:50:58 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
 	
int	main( void )
{
	Form		form("form", 5, 15);
	std::cout << form << std::endl;
	

	// Test with Good Grade for sign !
	std::cout << "Test with Good Grade for sign !" << std::endl;
	Bureaucrat	GoodSign("GoodSign", 1);
	std::cout << GoodSign << std::endl;
	
	GoodSign.signForm( form );
	


	// Test with Bad Grade for sign !
	std::cout << "\n\n\nTest with Bad Grade for sign !" << std::endl;
	Form	form2("form2", 5, 15);
	Bureaucrat	BadSign("BadSign", 10);
	std::cout << BadSign << std::endl;
	
	BadSign.signForm( form2 );
	

	// Test with a Good grade but the form is already signed !
	std::cout << "\n\n\nTest with a Good grade but the form is already signed !" << std::endl;
	Bureaucrat	AlreadySign("AlreadySign", 1);
	std::cout << AlreadySign << std::endl;
	
	AlreadySign.signForm( form );
	
	

	// Test creation of a Form with bad Grades
	std::cout << "\n\n\nTest creation of a Form with bad Grades !" << std::endl;
	
	try {
		Form	BadForm("Badform", 10, 0);
		std::cout << BadForm << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		Form 	BadForm2("Badform2", 400, 1);
		std::cout << BadForm2 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}