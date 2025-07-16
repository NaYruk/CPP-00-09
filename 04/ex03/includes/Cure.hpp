/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:49:23 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/16 13:02:31 by mmilliot         ###   ########.fr       */
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
		~Cure( void );
		
		Cure* clone() const;
		void	use( ICharacter& target );
};