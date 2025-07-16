/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:22:08 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/16 13:45:36 by mmilliot         ###   ########.fr       */
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
		~AMateria( void );
		
		std::string const & getType() const; //Return the materia type

		virtual	AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};