/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:07:14 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 16:27:09 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _materia_sources[4];
	
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource& copy );
		MateriaSource& operator=( const MateriaSource& copy );
		virtual ~MateriaSource( void );
		
		void	learnMateria(AMateria* to_copy);
		AMateria*	createMateria( std::string const & type );
};