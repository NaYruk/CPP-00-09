/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:36:08 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 16:24:54 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria( void ) : _materia_type("Default") {}

AMateria::AMateria( const AMateria& copy )
{
	(void)copy;
	return ;
}

AMateria::AMateria( std::string const & type ) : _materia_type(type) {}

AMateria& AMateria::operator=( const AMateria& copy )
{
	(void)copy;
	return *this;
}

AMateria::~AMateria( void ) {}


std::string const & AMateria::getType( void ) const
{
	return this->_materia_type;
}

void	AMateria::use(ICharacter& target)
{
	return ;
}


