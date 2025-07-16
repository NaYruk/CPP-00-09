/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:11:57 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/16 11:31:57 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	inventory[4];
		AMateria*	ground_materia[1000];
	
	public:
		Character( void ); 
		Character( const std::string name );
		Character( const Character& copy );
		Character& operator=( const Character& copy );
		~Character( void );
		
		std::string const & getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};