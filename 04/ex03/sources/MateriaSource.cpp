/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:06:05 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 16:25:53 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
		this->_materia_sources[i] = NULL;
	return ;
}

MateriaSource::MateriaSource( const MateriaSource& copy )
{
    for (int i = 0; i < 4; i++)
        this->_materia_sources[i] = NULL;
    
    for (int i = 0; i < 4; i++)
    {
        if (copy._materia_sources[i] != NULL)
            this->_materia_sources[i] = copy._materia_sources[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=( const MateriaSource& copy )
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia_sources[i] != NULL)
				delete this->_materia_sources[i];
		}
		
		for (int i = 0; i < 4; i++)
		{
			if (copy._materia_sources[i] != NULL)
				this->_materia_sources[i] = copy._materia_sources[i]->clone();
			else
				this->_materia_sources[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia_sources[i] != NULL)
			delete this->_materia_sources[i];
	}
	return ;
}

void	MateriaSource::learnMateria(AMateria* to_copy)
{
	if (to_copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia_sources[i] == NULL)
			{
				this->_materia_sources[i] = to_copy->clone();
				delete to_copy;
				return ;
			}
		}
		std::cout << "MateriaSource is Full ! You can put 4 Materia in MateriaSource !" << std::endl;
		delete to_copy;
	}
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 3; i >= 0; i--)
	{
		if (this->_materia_sources[i] != NULL && this->_materia_sources[i]->getType() == type)
		{
			return this->_materia_sources[i]->clone();
		}
	}
	return 0;
}