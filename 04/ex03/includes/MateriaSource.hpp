/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:07:14 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/16 13:19:01 by mmilliot         ###   ########.fr       */
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
		~MateriaSource( void );
		
		void	learnMateria(AMateria* to_copy);
		AMateria*	createMateria( std::string const & type );
};