/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:36:16 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/31 13:41:48 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

int main( void )
{
    std::cout << GREEN "TEST WITH AN ARRAY OF INT" RESET << std::endl;
    Array<int> arrayInt( 15 );

    try {
        // Good Index, and print
        for (unsigned int i = 0; i < 15; i++)
            arrayInt.assign(i, i);
        for (unsigned int i = 0; i < 15; i++)
            std::cout << "Tab Int index : " << i << " is : " << arrayInt.print(i) << std::endl;
        
        // Test With the operator [] overload !
        std::cout << "Test with operator[]: arrayInt[5] = " << arrayInt[5] << std::endl;

        // Try to do a deep copy !
        Array<int> arrayIntCopy = Array<int>( arrayInt );
        std::cout << "Index 10 before change : Original : " << arrayInt.print(10) << " Copy : " << arrayIntCopy.print(10) << std::endl;
        arrayIntCopy.assign(10, 42);
        std::cout << "Index 10 After change in Copy : Original : " << arrayInt.print(10) << " Copy : " << arrayIntCopy.print(10) << std::endl;
        
        // Try to print with an invalid index !
        std::cout << arrayInt.print(15) << std::endl; // THROW THE ERROR !
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    




    
    std::cout <<  GREEN "\n\n\nTEST WITH AN ARRAY OF CHAR" RESET << std::endl;
    Array<char> Alphabet( 26 );
    
    try {
        // Good Index, and print
        for (unsigned int i = 0; i < 26; i++)
            Alphabet.assign(i, i + 97);
        for (unsigned int i = 0; i < 26; i++)
            std::cout << "Tab Char index : " << i << " is : " << Alphabet.print(i) << std::endl;
        
        // Test With the operator [] overload !
        std::cout << "Test with operator[]: Alphabet[5] = " << Alphabet[5] << std::endl;

        // Try to do a deep copy !
        Array<char> AlphabetCopy = Array<char>( Alphabet );
        std::cout << "Index 10 before change : Original : " << Alphabet.print(10) << " Copy : " << AlphabetCopy.print(10) << std::endl;
        AlphabetCopy.assign(10, 126);
        std::cout << "Index 10 After change in Copy : Original : " << Alphabet.print(10) << " Copy : " << AlphabetCopy.print(10) << std::endl;
        
        // Try to print with an invalid index !
        std::cout << Alphabet.print(-2) << std::endl; // THROW THE ERROR !
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    
    
    return 0;
}