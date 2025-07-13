/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/11 19:17:56 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

int main( void )
{
    ClapTrap    rbOne("rbOne");
    ClapTrap    rbTwo("rbTwo");
    ClapTrap    rbThree("rbThree");

    std::cout << std::endl;
    
    rbOne.attack("rbTwo");
    rbTwo.takeDamage(10);
    rbTwo.beRepaired(5);
    
    std::cout << std::endl;

    rbThree.attack("rbOne");
    rbOne.takeDamage(2);
    rbOne.beRepaired(1);
    
    std::cout << std::endl;

    for(int i = 0; i < 4; i++)
    {
        rbThree.attack("rbOne");
        rbOne.takeDamage(2);
    }

    std::cout << std::endl;

    for(int i = 0; i < 10; i++)
        rbThree.attack("rbOne");
       
    std::cout << std::endl;

    rbOne.takeDamage(2);
    
    std::cout << std::endl;

    return 0;
}