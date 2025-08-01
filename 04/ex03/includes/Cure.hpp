/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:49:23 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 16:26:57 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure( void );
		Cure( const Cure& copy);
		Cure& operator=( const Cure& copy );
		virtual ~Cure( void );
		
		Cure* clone() const;
		void	use( ICharacter& target );
};