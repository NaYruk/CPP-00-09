/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:51:47 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/12 09:57:51 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string string = "HI THIS IS BRAIN";

	std::string *stringSTR = &string;

	std::string &stringREF = string;
	
	std::cout << "Memory adress of the string variable : " << &string << std::endl;
	std::cout << "Memory adress of the stringPRT : " << stringSTR << std::endl;
	std::cout << "Memory adress of the stringREF : " << &stringREF << std::endl;

	std::cout << "value of the string variable : " << string << std::endl;
	std::cout << "value of the stringPTR variable : " << *stringSTR << std::endl;
	std::cout << "value of the stringREF variable : " << stringREF << std::endl;
	
	return 0;
}