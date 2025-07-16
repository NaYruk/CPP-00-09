/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/16 19:45:16 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap("Default_clap_name"), _name("Default")
{
    std::cout << "Default constructor of DiamondTrap called" << std::endl;
    this->_HitPoints = this->FragTrap::_HitPoints;
    this->_AttackDamage = this->FragTrap::_AttackDamage;
    this->_EnergyPoints = this->ScavTrap::_EnergyPoints;
    return ;
}

DiamondTrap::DiamondTrap( const std::string name ) : ClapTrap(name + "_clap_name"), _name(name)
{
    std::cout << "DiamondTrap Construtor ✅ with name : " << this->_name << " is called" << std::endl;
    this->_HitPoints = this->FragTrap::_HitPoints;
    this->_AttackDamage = this->FragTrap::_AttackDamage;
    this->_EnergyPoints = this->ScavTrap::_EnergyPoints;
    return ;
}

DiamondTrap::DiamondTrap( const DiamondTrap& copy ) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    std::cout << "DiamondTrap copy constructor ✅ called" << std::endl;
    *this = copy;
    return ;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& copy)
{
    std::cout << "DiamondTrap Assignation operator called" << std::endl;
    this->_HitPoints = copy._HitPoints;
    this->_EnergyPoints = copy._EnergyPoints;
    this->_AttackDamage = copy._AttackDamage;
    this->_name = copy._name;
    this->ClapTrap::_name = copy.ClapTrap::_name;
    
    return *this;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << "DiamondTrap Destructor ❌ with name : " << this->_name << " is called" << std::endl;
    return ;
}



void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
    return ;
}

void    DiamondTrap::whoAmI( void )
{
    std::cout << "This is my Diamond Name 💎 : " << this->_name << std::endl;
    std::cout << "This is my ClapTrap Name : " << this->ClapTrap::_name << std::endl;
    return ;
}
