/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/11 20:56:03 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
    std::cout << "ScavTrap default constructor ✅ called, im not THE IDIOT OF ClapTrap !!!" << std::endl;
}

ScavTrap::ScavTrap( const std::string& name ) : ClapTrap(name)
{
    this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
     std::cout << "ScavTrap Construtor ✅ with name : " << this->_name << " is called, im not THE IDIOT OF ClapTrap !!!" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& copy )
{
    std::cout << "ScavTrap copy constructor ✅ called, im not THE IDIOT OF ClapTrap !!!" << std::endl;
    *this = copy;
    return ;
}

 ScavTrap& ScavTrap::operator=( const ScavTrap& copy )
 {
    std::cout << "ScavTrap assignation operator called im not THE IDIOT OF ClapTrap !!!" << std::endl;
    this->_name = copy._name;
    this->_HitPoints = copy._HitPoints;
    this->_EnergyPoints = copy._EnergyPoints;
    this->_AttackDamage = copy._AttackDamage;
    return *this;
 }


ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTrap Destructor ❌ with name : " << this->_name << " is called, im not THE IDIOT OF ClapTrap !!!" << std::endl;
}




void    ScavTrap::attack( const std::string& target )
{
    if (this->_EnergyPoints > 0 && this->_HitPoints > 0)
    {
        std::cout << "ScavTrap say : im not THE IDIOT OF ClapTrap !!! and " << this->_name << " attacks " << target << ", causing "
                  << this->_AttackDamage << " points of damage ! ⚔️" << std::endl;
        this->_EnergyPoints -= 1;
    }
    else if (this->_HitPoints == 0)
        std::cout << "ScavTrap say : im not THE IDIOT OF ClapTrap !!! and " << this->_name << " can't attack ! he is DEAD ! ☠️" << std::endl;
    else
        std::cout << "ScavTrap say : im not THE IDIOT OF ClapTrap !!! and " << this->_name << " can't attack ! he has no Energy ! 🪫" << std::endl;
    return ;
}


void    ScavTrap::guardGate( void )
{
    std::cout << "🪖 IM ScavTrap AND MY NAME IS : " << this->_name << " AND NOW IM IN GATE KEEPER MODE 🪖" << std::endl;
    return ;
}



