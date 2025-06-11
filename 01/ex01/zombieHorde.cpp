/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:22:48 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/11 17:41:21 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N <= 0){
		std::cout << "Number of Zombies is <= 0 !" << std::endl;
		return (NULL);
	}
	
	Zombie	*zombieArray = new Zombie[N];
	
	for (int i = 0; i < N; i++){
		zombieArray[i].setName(name);
	}
	
	return (&zombieArray[0]);
}
