/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/24 16:25:09 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main( void )
{
    std::cout << "CREATION OF ARRAY WITH 5 Dogs AND 5 Cats";
    std::cout << std::endl;

    const Animal* array_animals[10];
    
    for(int i = 0; i < 10; i++)
    {
        if (i < 5)
            array_animals[i] = new Cat();
        else
            array_animals[i] = new Dog();
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Subject Test" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;
    
    delete j;
    delete i;

    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "DELETE ARRAY" << std::endl;
    for(int i = 0; i < 10; i++)
        delete array_animals[i];

    return 0;
}