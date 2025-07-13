/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/11 20:54:28 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("NoName"), _HitPoints(10),
_EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "ClapTrap default constructor ✅ called" << std::endl;
}

ClapTrap::ClapTrap( const std::string name ) : _name(name), _HitPoints(10),
_EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "ClapTrap Construtor ✅ with name : " << this->_name << " is called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& copy )
{
    std::cout << "ClapTrap copy constructor ✅ called" << std::endl;
    *this = copy;
    return ;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& copy )
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    this->_name = copy._name;
    this->_HitPoints = copy._HitPoints;
    this->_EnergyPoints = copy._EnergyPoints;
    this->_AttackDamage = copy._AttackDamage;
    return *this;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "ClapTrap Destructor ❌ with name : " << this->_name << " is called" << std::endl;
}




void    ClapTrap::attack( const std::string& target )
{
    if (this->_EnergyPoints > 0 && this->_HitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
                  << this->_AttackDamage << " points of damage ! ⚔️" << std::endl;
        this->_EnergyPoints -= 1;
    }
    else if (this->_HitPoints == 0)
        std::cout << "ClapTrap " << this->_name << " can't attack ! he is DEAD ! ☠️" << std::endl;
    else
        std::cout << "ClapTrap " << this->_name << " can't attack ! he has no Energy ! 🪫" << std::endl;
    return ;
}

void    ClapTrap::beRepaired( unsigned int amount )
{
    if (this->_EnergyPoints > 0 && _HitPoints > 0)
    {
        this->_HitPoints += amount;
        this->_EnergyPoints -= 1;
        std::cout << "ClapTrap " << this->_name << " repairs himself by an amount of " << amount << " 🛡️" << " He has left " << this->_HitPoints << " HP ! ❤️" << std::endl;
    }
    else if (this->_HitPoints == 0)
        std::cout << "ClapTrap " << this->_name << " can't repairs himself ! he is DEAD ! ☠️" << std::endl;
    else
        std::cout << "ClapTrap " << this->_name << " can't repairs himself, he has no Energy ! 🪫" << std::endl;
    return ;
}

void    ClapTrap::takeDamage( unsigned int amount )
{
    if (this->_HitPoints >= amount)
        this->_HitPoints -= amount;
    else if(this->_HitPoints == 0 && amount > 0)
    {
        std::cout << "ClapTrap " << this->_name << " is already dead☠️, you can't hit a dead ClapTrap ! ⚠️" << std::endl;
        return ;
    }
    else
        this->_HitPoints = 0;
    std::cout << "ClapTrap " << this->_name << " was attacked ⚔️, he lost " << amount << " HP. He has left " << this->_HitPoints << " HP ! ❤️" << std::endl;
    return ;
}
