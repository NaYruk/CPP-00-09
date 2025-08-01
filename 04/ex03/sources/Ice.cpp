/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:49:29 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 16:22:33 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {}

Ice::Ice( const Ice& copy ) : AMateria("ice")
{
	(void)copy;
	return ;
}

Ice& Ice::operator=( const Ice& copy )
{
	(void)copy;
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