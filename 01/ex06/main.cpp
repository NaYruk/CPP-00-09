/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 04:30:03 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/17 04:39:36 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Please Write a valid level for Harl !" << std::endl, 1);
	
	std::string	level = argv[1];
	Harl harl;
	
	std::string level_array[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	int	level_reference = -1;
	
	for (int i = 0; i < 4; i++)
	{
		if (level == level_array[i])
			level_reference = i;
	}
	
	switch (level_reference)
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
	}
	
	return 0;
}