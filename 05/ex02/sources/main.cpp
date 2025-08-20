/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:35:25 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/20 18:22:23 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main( void )
{
	// TESTING OVERLOAD << OPERATOR
	// Overload operator test :
	std::cout << "\nTEST OPERATOR <<" << std::endl;
	
	Bureaucrat testOperator("TestOperator", 50);
	std::cout << testOperator << std::endl;
	
	
	
	
	// TEST BUREAUCRAT CONSTRUCTION (GRAD NBR)
	// Test High Grad
	std::cout << "\n\n\nTEST BUREAUCRAT CONSTRUCTION (GRAD NBR)" << std::endl;

	try {
		Bureaucrat testHighGrad("TestHighGrad", 0);
		std::cout << testHighGrad << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	// Test Low Grad
	try {
		Bureaucrat testLowGrad("TestLowGrad", 151);
		std::cout << testLowGrad << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}	
	
	// Test Good grad
	try {
		Bureaucrat testGoodGrad("TestGoodGrad", 50);
		std::cout << testGoodGrad << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	
	
	
	// TEST INCREMENT AND DECREMENT GRADE
	// Test Increment Grad
	std::cout << "\n\n\nTEST INCREMENT AND DECREMENT GRADE" << std::endl;
	
	Bureaucrat testIncrementGrad("TestIncrementGrad", 1);
	
	try {
		testIncrementGrad.incrementGrade();
		std::cout << testIncrementGrad << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	// Test Decrement Grad
	Bureaucrat testDecrementGrad("TestDecrementGrad", 150);
	
	try {
		testDecrementGrad.decrementGrade();
		std::cout << testDecrementGrad << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	// Test Good Incrementation
	Bureaucrat testGoodIncrementGrad("TestGoodIncrementGrad", 20);
	try {
		testGoodIncrementGrad.incrementGrade();
		std::cout << testGoodIncrementGrad << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	// Test Good Decrement Grad
	Bureaucrat testGoodDecrementGrad("TestGoodDecrementGrad", 20);
	try {
		testGoodDecrementGrad.decrementGrade();
		std::cout << testGoodDecrementGrad << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}