/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:49:18 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 16:23:24 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {}

Cure::Cure( const Cure& copy ) : AMateria("cure")
{
	(void)copy;
	return ;
}

Cure& Cure::operator=( const Cure& copy )
{
	(void)copy;
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
