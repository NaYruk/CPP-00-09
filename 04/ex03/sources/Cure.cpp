/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:49:18 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/16 18:23:46 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {}

Cure::Cure( const Cure& copy )
{
	this->_materia_type = copy._materia_type;
	return ;
}

Cure& Cure::operator=( const Cure& copy )
{
	this->_materia_type = copy._materia_type;
	return *this;
}

Cure::~Cure( void ) {}



Cure* Cure::clone( void ) const
{
	Cure* clone = new Cure(*this);
	
	return clone;
}

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}
