/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/11 20:41:35 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

int main( void )
{
    {
        std::cout << std::endl;
        std::cout << "SCAV TRAP TEST" << std::endl;
        std::cout << std::endl;
        
        ScavTrap    rbOne("rbOne");
        ScavTrap    rbTwo("rbTwo");
        ScavTrap    rbThree("rbThree");
         
        std::cout << std::endl;
        
        rbOne.attack("rbTwo");
        rbTwo.takeDamage(20);
        rbTwo.beRepaired(5);
    
        std::cout << std::endl;
    
        for(int i = 0; i < 4; i++)
        {
            rbThree.attack("rbOne");
            rbOne.takeDamage(20);
        }
        std::cout << std::endl;
    
        rbOne.takeDamage(20);
        
        std::cout << std::endl;
        
        rbTwo.guardGate();
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    {
        std::cout << "FRAG TRAP TEST" << std::endl;
        std::cout << std::endl;

        FragTrap    rbOne("rbOne");
        FragTrap    rbTwo("rbTwo");
        FragTrap    rbThree("rbThree");
         
        std::cout << std::endl;
        
        rbOne.attack("rbTwo");
        rbTwo.takeDamage(30);
        rbTwo.beRepaired(5);
    
        std::cout << std::endl;
    
        for(int i = 0; i < 4; i++)
        {
            rbThree.attack("rbOne");
            rbOne.takeDamage(30);
        }
        std::cout << std::endl;
    
        rbOne.takeDamage(30);
        
        std::cout << std::endl;
        
        rbTwo.highFivesGuys();
        std::cout << std::endl;
    }

    return 0;
}