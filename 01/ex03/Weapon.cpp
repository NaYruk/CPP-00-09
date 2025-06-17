/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:07:54 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/16 22:23:50 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
    return ;
}

Weapon::~Weapon()
{
    return ;
}

const std::string &Weapon::getType() const
{
    return (this->type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
    return ;
}
