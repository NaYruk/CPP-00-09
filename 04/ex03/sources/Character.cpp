/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:11:51 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/16 19:27:52 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character( void ) : _name("Default")
{
	for (int i = 0; i < 1000; i++)
		this->ground_materia[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	return ;
}

Character::Character( const std::string name ) : _name(name)
{
	for (int i = 0; i < 1000; i++)
		this->ground_materia[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	return ;
}

Character::Character( const Character& copy )
{
	*this = copy;
	return ;
}

Character&	Character::operator=( const Character& copy )
{
	this->_name = copy._name;

	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		
		if (copy.inventory[i] != NULL)
			this->inventory[i] = copy.inventory[i]->clone();
	}
	

	for (int i = 0; i < 1000; i++)
	{
		if (this->ground_materia[i] != NULL)
		{
			delete this->ground_materia[i];
			this->ground_materia[i] = NULL;
		}
		if (copy.ground_materia[i] != NULL)
			this->ground_materia[i] = copy.ground_materia[i]->clone();
	}
	return *this;
}

Character::~Character( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
	for (int i = 0; i < 1000; i++)
	{
		if (this->ground_materia[i] != NULL)
			delete this->ground_materia[i];
	}
	return ;
}


std::string const & Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] == m)
			{
				std::cout << "The materia : " << m->getType() << " at " << m << " is already in the inventory at the position " << i << std::endl;
				return ;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] == NULL)
			{
				this->inventory[i] = m;
				return ;
			}
		}
		delete m;
	}
	return ;
}

void	Character::unequip(int idx)
{
	if (this->inventory[idx] != NULL)
	{
		for (int i = 0; i < 1000; i++)
		{
			if (this->ground_materia[i] == NULL)
			{
				std::cout << this->getName() << "Drop the Materia on the ground : " << this->inventory[idx]->getType() << std::endl;
				this->ground_materia[i] = this->inventory[idx];
				this->inventory[idx] = NULL;
				return ;
			}
		}
		std::cout << "The ground is full of materials, you can't put any more down" << std::endl;
	}
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx > 3)
	{
		std::cout << "A Character have only 4 emplacement in their inventory, please select a Good index idx >= 0 && idx <= 3 !" << std::endl;
		return ;
	}
	if (this->inventory[idx] != NULL)
	{
		this->inventory[idx]->use(target);
		return ;
	}
	std::cout << "The emplacement : " << idx << " is empty." << std::endl;
	return ;
}
