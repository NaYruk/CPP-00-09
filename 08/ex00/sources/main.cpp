/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:35:55 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/31 22:07:51 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

int main( void )
{
    int myInts[] = {14, 2, -4, 142, -14, 14};


                        // Containers :
        //SEQUENTIAL
    // - Vector -> Dynamique Array, Fast by Index : vec[2]
    // - List -> Double Chained List, Fast add and suppresion in the middle, No Fast by Index : X list[2]
    // - Deque -> Double-ended-queue( Fast access on the beginning and the end)
    // - Array -> Fix Array (C++11)
    // - ForwardList -> Simple chained List (C++11)

        //ASSOCIATIF (KEYS / VALUES)
    // - Set -> Key = YES, Unique element, set sort
    // - Map -> Key = YES, Table of Key/Values sort
    // - Multiset -> Key = YES, Like set but with duplicates
    // - Multimap -> Key = YES, Like map but with duplicates

        //ASSOCIATIF (KEYS / VALUES) BUT NOT SORTED
    // - UnorderedSet -> Like set but not sorted
    // - UnorderedMap -> Like map but not sorted
    
    
    std::cout << GREEN "TRY WITH AN CONTAINER LIST OF INT" RESET << std::endl;
    try {
        std::list<int> testList (myInts, myInts + sizeof(myInts) / sizeof(int));
    
        std::list<int>::iterator itList = easyfind(testList, -14);          // VALID
    
        std::cout << "Value is : " << *itList << std::endl;
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    



    std::cout << GREEN "\n\n\nTRY WITH AN CONTAINER VECTOR OF INT" RESET << std::endl;
    try {
        std::vector<int> testVector(myInts, myInts + sizeof(myInts) / sizeof(int));

        std::vector<int>::iterator itVector = easyfind(testVector, -4);         // VALID

        std::cout << "Value is : " << *itVector << std::endl;
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }




    std::cout << GREEN "\n\n\nTRY WITH AN CONTAINER DEQUE OF INT" RESET << std::endl;
    try {
        std::deque<int> testDeque(myInts, myInts + sizeof(myInts) / sizeof(int));
        
        std::deque<int>::iterator itDeque = easyfind(testDeque, -2);          // INVALID

        std::cout << "Value is : " << *itDeque << std::endl;
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    
    return 0;
}