/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:11 by marcmilliot       #+#    #+#             */
/*   Updated: 2025/09/23 17:51:52 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char ** argv)
{
	if (argc != NBR_ARGUMENTS) {
		std::cerr << RED "The Number of arguments must be 2 !" RESET << std::endl;
		return -1;
	}
	
	try {
		RPN rpn;
		rpn.doReversePolishNotation(argv[1]);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	return 0;
}