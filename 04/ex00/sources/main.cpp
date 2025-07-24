/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/24 16:24:33 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main( void )
{
    {
        std::cout << "TEST WITH DOG CAT AND ANIMAL CLASS" << std::endl;
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
    
        std::cout << std::endl;
        std::cout << "TYPE OF ANIMAL :" << std::endl;
        
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
    
        std::cout << std::endl;
        std::cout << "SOUND OF EACH ANIMALS :" << std::endl;
        
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        std::cout << std::endl;
    
        delete meta;
        delete j;
        delete i;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    {
        std::cout << "TEST WITH DOG WRONGCAT AND WRONGANIMAL CLASS" << std::endl;
        const WrongAnimal* meta = new WrongAnimal();
        const Animal* j = new Dog();
        const WrongAnimal* i = new WrongCat();
    
        std::cout << std::endl;
        std::cout << "TYPE OF ANIMAL :" << std::endl;
        
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
    
        std::cout << std::endl;
        std::cout << "SOUND OF EACH ANIMALS :" << std::endl;
        
        i->makeSound(); //will output the dog sound!
        j->makeSound();
        meta->makeSound();
        std::cout << std::endl;
    
        delete meta;
        delete j;
        delete i; 
    }
    return 0;   
}