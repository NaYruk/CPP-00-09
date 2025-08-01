/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:49:28 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 16:27:01 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice( void );
		Ice( const Ice& copy);
		Ice& operator=( const Ice& copy );
		virtual ~Ice( void );
		
		Ice* clone() const;
		void	use( ICharacter& target );
};