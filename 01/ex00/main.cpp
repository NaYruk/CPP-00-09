/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:01:50 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/11 17:02:27 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int	main()
{
	Zombie *new_zombie = newZombie("Jojo");
	new_zombie->announce();

	randomChump("random_zombie1");
	randomChump("random_zombie2");
	randomChump("random_zombie3");
	
	Zombie *new_zombie2 = newZombie("Bernard");
	new_zombie->announce();

	delete(new_zombie);
	delete(new_zombie2);
	
	return 0;
}
