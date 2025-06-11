/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:03:46 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/11 17:42:02 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int	main()
{
	ssize_t	N = 10;
	
	Zombie *zombieArray = zombieHorde(10, "jojo");
	if (!zombieArray)
		return (1);
		
	for(ssize_t i = 0; i < N; i++){
		zombieArray[i].announce();
	}

	delete[] zombieArray;
	return 0;
}