/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/16 19:44:57 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

class   DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap( void );
        DiamondTrap( const std::string name );
        DiamondTrap( const DiamondTrap& copy);
        DiamondTrap& operator=( const DiamondTrap& copy );
        virtual ~DiamondTrap( void );

        void	attack( const std::string& target );
        void    whoAmI();
        
    private:
        std::string	_name;
};