/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:36:08 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/16 13:43:04 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria( void ) : _materia_type("Default") {}

AMateria::AMateria( const AMateria& copy )
{
	this->_materia_type = copy._materia_type;
	return ;
}

AMateria::AMateria( std::string const & type ) : _materia_type(type) {}

AMateria& AMateria::operator=( const AMateria& copy )
{
	this->_materia_type = copy._materia_type;
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


