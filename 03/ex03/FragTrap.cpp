/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 16:16:34 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
    std::cout << "FragTrap default constructor ✅ called, IM WARN YOU IM NOT SCAVTRAP OR CLAPTRAP IM UNIQUE IN THIS WORLD !" << std::endl;
    this->_HitPoints = 300;
    this->_EnergyPoints = 100;
    this->_AttackDamage = 30;
    return ;
}

FragTrap::FragTrap( const std::string& name ) : ClapTrap(name)
{
    std::cout << "FragTrap Construtor ✅ with name : " << this->_name << " is called, IM WARN YOU IM NOT SCAVTRAP OR CLAPTRAP IM UNIQUE IN THIS WORLD !" << std::endl;
    this->_HitPoints = 300;
    this->_EnergyPoints = 100;
    this->_AttackDamage = 30;
    return ;  
}

FragTrap::FragTrap( const FragTrap& copy )
{
    std::cout << "FragTrap copy constructor ✅ called, IM WARN YOU IM NOT SCAVTRAP OR CLAPTRAP IM UNIQUE IN THIS WORLD !" << std::endl;
    *this = copy;
    return ;
}

FragTrap& FragTrap::operator=( const FragTrap& copy )
{
    std::cout << "FragTrap assignation operator called, IM WARN YOU IM NOT SCAVTRAP OR CLAPTRAP IM UNIQUE IN THIS WORLD !" << std::endl;
    this->_HitPoints = copy._HitPoints;
    this->_EnergyPoints = copy._EnergyPoints;
    this->_AttackDamage = copy._AttackDamage;
    return *this;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap  Destructor ❌ with name : " << this->_name << " is called, IM WARN YOU IM NOT SCAVTRAP OR CLAPTRAP IM UNIQUE IN THIS WORLD !" << std::endl;
}

void    FragTrap::highFivesGuys( void )
{
    std::cout << "FragTrap " << this->_name << " says: Hey guys, high five! ✋" << std::endl;
}