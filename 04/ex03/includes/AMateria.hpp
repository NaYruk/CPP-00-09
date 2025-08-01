/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:22:08 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 16:26:47 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "./ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_materia_type;
	
	public:
		AMateria( void );
		AMateria( std::string const & type );
		AMateria( const AMateria& copy );
		AMateria& operator=( const AMateria& copy );
		virtual ~AMateria( void );
		
		std::string const & getType() const;

		virtual	AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};