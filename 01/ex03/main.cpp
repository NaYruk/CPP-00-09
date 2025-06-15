/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:07:54 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/15 21:39:16 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

int main()
{
    Weapon  weapon;
    Weapon  weapon2;

    weapon.setType("Shotgun");
    weapon2.setType("Pistolet");

    std::cout << "Arme 1 : " << weapon.getType() << std::endl;
    std::cout << "Arme 2 : " << weapon2.getType() << std::endl;

    return 0;
}

