/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:07:54 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/16 21:23:08 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Weapon.hpp"

class HumanA
{
    private:
        Weapon      &weapon;
        std::string name;
        
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void    attack() const;
};
