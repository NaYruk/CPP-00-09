/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:49:29 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/16 13:46:00 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {}

Ice::Ice( const Ice& copy )
{
	this->_materia_type = copy._materia_type;
	return ;
}

Ice& Ice::operator=( const Ice& copy )
{
	this->_materia_type = copy._materia_type;
	return *this;
}

Ice::~Ice( void ) {}



Ice* Ice::clone( void ) const
{
	Ice* clone = new Ice(*this);
	
	return clone;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}