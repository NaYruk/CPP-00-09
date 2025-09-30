/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:11 by marcmilliot       #+#    #+#             */
/*   Updated: 2025/09/30 20:16:47 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

static bool    argsValids(int argc, char ** argv)
{
    if (argc < MINIMUM_ARGUMENTS) {
        std::cerr << RED "There must be at least 2 arguments." RESET << std::endl;
        return false;
    }

    for (size_t i = 1; argv[i] != NULL; i++)
    {
        for (size_t j = 0; argv[i][j] != '\0'; j++) {
            if (!std::isdigit(argv[i][j])) {
                std::cerr << RED "Not all arguments are numbers / positive numbers : " << argv[i] << RESET << std::endl;
                return false;
            }
        }
        errno = 0;
        long    longArg = std::strtol(argv[i], NULL, 10);
        if (errno == ERANGE || longArg > std::numeric_limits<int>::max()) {
            std::cerr << RED "Overflow detected, the number is not an INT : " << argv[i] << RESET << std::endl;
            return false;
        }
        else if (longArg < 0) {
            std::cerr << RED "Not all arguments is positive numbers : " << argv[i] << RESET << std::endl;
            return false;
        }
    }
    return true;
}

int main(int argc, char ** argv)
{
    if (argsValids(argc, argv) == false)
        return 1;

    try {
        PmergeMe sorter;
        sorter.sortWithVector(argv);
        std::cout << std::endl;
        sorter.sortWithDeque(argv);
    }
    catch(std::exception & e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    return 0;
}
