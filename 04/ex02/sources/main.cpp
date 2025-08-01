/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 16:02:16 by marcmilliot      ###   ########.fr       */
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

    Animal* array_animals[10];
    
    for(int i = 0; i < 10; i++)
    {
        if (i < 5)
            array_animals[i] = new Cat();
        else
            array_animals[i] = new Dog();
    }

    std::cout << std::endl << "PUT SOME IDEAS IN THE FIRST ANIMAL" << std::endl << std::endl;
    for(int i = 0; i < 50; i++)
    {
        std::string idea = "Idea Number : " + std::to_string(i + 1);
        array_animals[0]->addIdea(idea);
    }
    std::cout << "PRINT THE IDEAS" << std::endl;
    array_animals[0]->showIdeas();

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



    std::cout << std::endl << "DEEP COPY TESTS" << std::endl;
    std::cout << "Creating original cat with ideas..." << std::endl;
    Cat original_cat;
    original_cat.addIdea("Original idea 1");
    original_cat.addIdea("Original idea 2");
    original_cat.addIdea("Original idea 3");

    std::cout << "Original cat ideas:" << std::endl;
    original_cat.showIdeas();

    std::cout << std::endl << "Creating a copy of cat..." << std::endl; 
    Cat copied_cat = original_cat;
    
    std::cout << "Adding idea to original cat..." << std::endl;
    original_cat.addIdea("New idea in original");
    
    std::cout << "Adding different idea to copied cat..." << std::endl;
    copied_cat.addIdea("New idea in copy");
    
    std::cout << "\nOriginal cat ideas after modification:" << std::endl;
    original_cat.showIdeas();
    
    std::cout << "\nCopied cat ideas after modification:" << std::endl;
    copied_cat.showIdeas();
    std::cout << std::endl;
    

    
    //Test for the abstract class
    //Animal animal; //Error
    //new Animal; // Error
    //Cat cat; // OK
    //Animal* ptr = new Cat(); // OK
    
    return 0;
}