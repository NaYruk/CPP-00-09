/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 14:57:43 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "./ClapTrap.hpp"

class   ScavTrap : public ClapTrap
{
    public:
        ScavTrap( void );
        ScavTrap( const std::string& name );
        ScavTrap( const ScavTrap& copy );
        ScavTrap& operator=( const ScavTrap& copy );
        virtual ~ScavTrap( void );
        
		void	attack( const std::string& target );
        void    guardGate();
};