/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:09:20 by mmilliot          #+#    #+#             */
/*   Updated: 2025/09/09 04:29:42 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main( void )
{
    // SUBJECT TEST !
    std::cout << "SUBJECT TEST !" << std::endl;
    Span sp = Span(5);
    
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }



    // MY TEST
    srand(time(NULL));
    std::cout << "\n\nMY TEST !" << std::endl;
    std::cout << "\nTEST WITH 10 000 NUMBERS !" << std::endl;
    Span sp2 = Span(10000);

    try {
        std::vector<int> reserve;
        for (int i = 0; i < 10000; i++) {
            reserve.push_back(rand());
        }
        sp2.addRange(reserve.begin(), reserve.end());
    
        //sp2.printSpan();                  //IF YOU WANT SEE 10 000 NUMBERS IN THE VECTOR CONTAINER
        //std::cout << "\n" << std::endl;
        
        std::cout << "Shortest Span : " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }




    std::cout << "\nTEST WITH 1 000 000 NUMBERS !" << std::endl;
    Span sp3 = Span(1000000);

    try {
        std::vector<int> reserve2;
        for (int i = 0; i < 1000000; i++) {
            reserve2.push_back(rand());
        }
        sp3.addRange(reserve2.begin(), reserve2.end());
        
        std::cout << "Shortest Span : " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << sp3.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    



    std::cout << "\nTEST FOR THROW EXCEPTIONS !" << std::endl;
    Span sp4 = Span(12);

    try {
        std::cout << "Shortest Span : " << sp4.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Longest Span : " << sp4.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
        
    


    std::cout << "\nTEST WITH 10 NUMBERS !" << std::endl;
    Span sp5 = Span(5);

    try {
        sp5.addNumber(1);
        sp5.addNumber(5);
        sp5.addNumber(15);
        sp5.addNumber(62);
        sp5.addNumber(34);
        sp5.printSpan();
        
        std::cout << "\nShortest Span : " << sp5.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << sp5.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}