/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:35:25 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/22 16:39:24 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
 	
int	main( void )
{
	std::cout << " SHRUBBERY TEST !!!!! " << std::endl;
	// Test with a Good Grade for all
	std::cout << "\nTest with a Good Grade !" << std::endl;
	Bureaucrat	bGoodForShrubbery("bGoodForShrubbery", 10);
	ShrubberyCreationForm	gardenShrubbery("Garden");
	
	bGoodForShrubbery.signForm( gardenShrubbery );	  //sign the Form
	std::cout << gardenShrubbery << std::endl;        //print Form info
	gardenShrubbery.execute( bGoodForShrubbery );     //Execute the action of Shrubbery
	

	// Test with a Bad Grade for Exec but Good for Sign
	std::cout << "\n\nTest with a Bad Grade for Exec but Good for Sign !" << std::endl;
	Bureaucrat	bBadForShrubbery("bBadForShrubbery", 140);
	ShrubberyCreationForm	gardenShrubbery2("Garden");
	
	bBadForShrubbery.signForm( gardenShrubbery2 );	  //sign the Form
	std::cout << gardenShrubbery2 << std::endl;        //print Form info
	gardenShrubbery2.execute( bBadForShrubbery );     //Execute the action of Shrubbery
	

	// Test with a Bad Grade for Exec and Sign
	std::cout << "\n\nTest with a Bad Grade for Exec and Sign !" << std::endl;
	Bureaucrat	bBadSignForShrubbery("bBadSignForShrubbery", 149);
	ShrubberyCreationForm	gardenShrubbery3("Garden");
	
	bBadSignForShrubbery.signForm( gardenShrubbery3 );	  //sign the Form
	std::cout << gardenShrubbery3 << std::endl;        //print Form info
	gardenShrubbery3.execute( bBadSignForShrubbery );     //Execute the action of Shrubbery
	



	


	
	std::cout << "\n\n\n\n\n ROBOTOMY TEST !!!!! " << std::endl;
	// Test with a Good Grade for all
	std::cout << "\nTest with a Good Grade !" << std::endl;
	Bureaucrat	bGoodForRobotomy("bGoodForRobotomy", 10);
	RobotomyRequestForm	GarageRobotomy("Garage");
	
	bGoodForRobotomy.signForm( GarageRobotomy );	  //sign the Form
	std::cout << GarageRobotomy << std::endl;        //print Form info
	GarageRobotomy.execute( bGoodForRobotomy );     //Execute the action of Robotomy
	

	// Test with a Bad Grade for Exec but Good for Sign
	std::cout << "\n\nTest with a Bad Grade for Exec but Good for Sign !" << std::endl;
	Bureaucrat	bBadForRobotomy("bBadForRobotomy", 50);
	RobotomyRequestForm	GarageRobotomy2("Garage");
	
	bBadForRobotomy.signForm( GarageRobotomy2 );	  //sign the Form
	std::cout << GarageRobotomy2 << std::endl;        //print Form info
	GarageRobotomy2.execute( bBadForRobotomy );     //Execute the action of Robotomy
	

	// Test with a Bad Grade for Exec and Sign
	std::cout << "\n\nTest with a Bad Grade for Exec and Sign !" << std::endl;
	Bureaucrat	bBadSignForRobotomy("bBadSignForRobotomy", 149);
	RobotomyRequestForm	GarageRobotomy3("Garage");
	
	bBadSignForRobotomy.signForm( GarageRobotomy3 );	  //sign the Form
	std::cout << GarageRobotomy3 << std::endl;        //print Form info
	GarageRobotomy3.execute( bBadSignForRobotomy );     //Execute the action of Robotomy
	





	

		std::cout << "\n\n\n\n\n Presidential TEST !!!!! " << std::endl;
	// Test with a Good Grade for all
	std::cout << "\nTest with a Good Grade !" << std::endl;
	Bureaucrat	bGoodForPresidential("bGoodForPresidential", 2);
	PresidentialPardonForm	OfficePresidential("Office");
	
	bGoodForPresidential.signForm( OfficePresidential );	  //sign the Form
	std::cout << OfficePresidential << std::endl;        //print Form info
	OfficePresidential.execute( bGoodForPresidential );     //Execute the action of Presidential
	

	// Test with a Bad Grade for Exec but Good for Sign
	std::cout << "\n\nTest with a Bad Grade for Exec but Good for Sign !" << std::endl;
	Bureaucrat	bBadForPresidential("bBadForPresidential", 15);
	PresidentialPardonForm	OfficePresidential2("Office");
	
	bBadForPresidential.signForm( OfficePresidential2 );	  //sign the Form
	std::cout << OfficePresidential2 << std::endl;        //print Form info
	OfficePresidential2.execute( bBadForPresidential );     //Execute the action of Presidential
	

	// Test with a Bad Grade for Exec and Sign
	std::cout << "\n\nTest with a Bad Grade for Exec and Sign !" << std::endl;
	Bureaucrat	bBadSignForPresidential("bBadSignForPresidential", 149);
	PresidentialPardonForm	OfficePresidential3("Office");
	
	bBadSignForPresidential.signForm( OfficePresidential3 );	  //sign the Form
	std::cout << OfficePresidential3 << std::endl;        //print Form info
	OfficePresidential3.execute( bBadSignForPresidential );     //Execute the action of Presidential


	
	return 0;
}