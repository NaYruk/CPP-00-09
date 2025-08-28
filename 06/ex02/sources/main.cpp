/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:12:10 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/28 20:41:52 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <ctime>
#include <cstdlib>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

static  Base* generate( void )
{ 
    int random_nbr = -1;
    random_nbr = rand() % 3;    //Random With 3 possibility

    Base* base = NULL;
    switch ( random_nbr )
    {
        case 0:
            base = new A;
            break ;
            
        case 1:
            base = new B;
            break ;
        
        case 2:
            base = new C;
            break ;
    }
    
    return base;
}

static  void identify( Base* p )
{
    if (p)
    {
        if (dynamic_cast<A*>(p))
            std::cout << "The type is : A" << std::endl;
        else if (dynamic_cast<B*>(p))
            std::cout << "The type is : B" << std::endl;
        else if (dynamic_cast<C*>(p))
            std::cout << "The type is : C" << std::endl;
        else
            std::cout << RED << "Unknown Type !" << RESET << std::endl;
    }
    else
        std::cout << RED << "NULL POINTER DETECTED !" << RESET << std::endl;
}

static  void identify( Base& p )
{
    try {
        A& type = dynamic_cast<A&>(p);
        (void)type;
        std::cout << "The type is : A !" << std::endl;
    }
    catch (std::exception& e) {
        try {
            B& type = dynamic_cast<B&>(p);
            (void)type;
            std::cout << "The type is : B !" << std::endl;
        }
        catch (std::exception& e) {
            try {
                C& type = dynamic_cast<C&>(p);
                (void)type;
                std::cout << "The type is : C !" << std::endl;
            }
            catch (std::exception& e) {
                std::cout << RED << "Unknown type : " << e.what() << RESET << std::endl;
            }
        }
    }    
}


int main( void )
{
    srand(time(NULL)); //Reset the seed of rand function
        
    std::cout << "TEST WITH POINTERS :" << std::endl;
    Base* test = generate();
    Base* test1 = generate();
    Base* test2 = generate();

    identify(test);
    identify(test1);
    identify(test2);
    

    std::cout << "\n\n\nTEST WITH ADRESSE :" << std::endl;
    Base& test3 = *generate();
    Base& test4 = *generate();
    Base& test5 = *generate();

    identify(test3);
    identify(test4);
    identify(test5);    

    
    std::cout << "\n\n\nTEST BAD TYPES :" << std::endl;
    Base* test6 = new Base;
    
    identify(test6);
    identify(NULL);




    // Correct Leaks !
    delete test;
    delete test1;
    delete test2;
    delete &test3;
    delete &test4;
    delete &test5;
    delete test6;
    
    return 0;
}