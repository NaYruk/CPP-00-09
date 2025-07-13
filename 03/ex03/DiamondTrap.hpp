/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 16:47:12 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

class   DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        DiamondTrap( void );
        DiamondTrap( const std::string name );
        DiamondTrap( const DiamondTrap& copy);
        DiamondTrap& operator=( const DiamondTrap& copy );
        virtual ~DiamondTrap( void );

        void	attack( const std::string& target );
        void    whoAmI();

        void    getAllData() const;
        
    private:
        std::string	_name;
};