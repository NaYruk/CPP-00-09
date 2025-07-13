/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 14:58:10 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class   ClapTrap
{
    public:
        ClapTrap( void );
        ClapTrap( const std::string name );
        ClapTrap( const ClapTrap& copy );
        ClapTrap& operator=( const ClapTrap& copy );
        virtual ~ClapTrap( void );

		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

    protected:
        std::string	_name;
		int			_HitPoints;
		int			_EnergyPoints;
		int			_AttackDamage;
};