/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:36:16 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/31 13:25:02 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

void    print( int const & nbr ) {
    std::cout << "INT = " << nbr << std::endl;
    return ;
}

template< class T >
void    TemplatePrint( T const & element ) { 
    std::cout << element << std::endl;
}

void    toUpper( char & c ) {
    c = std::toupper(c);
    return ;
}

void    Incrementation( float & element ) {
    element++;
    return ;
}



int main( void )
{
    std::cout << "Test with an array of Int, and print the tab\n" << std::endl;
    int IntArray[] = {1, 12, 2, -3, 522, 34};
    
    iter<int>(IntArray, 6, print);




    
    std::cout << "\n\n\nTest with an array of Char, and apply the toupper function, and print !\n" << std::endl;
    char charArray[] = {'a', 'b', 'c', 'D', 'e'};

    iter<char>(charArray, 5, toUpper);
    iter<char>(charArray, 5, TemplatePrint<char>);


    

    //std::cout << "\n\n\nTest with a const float array, and try to modify the content of the array !\n" << std::endl;
    //float const floatConstArray[] = {42.0f, 12.0f, -1.0f};
    //iter<float const>(floatConstArray, 3, Incrementation);                    // ERROR : float array is const, and try to increment, const element of the array
    //iter<float const>(floatConstArray, 3, TemplatePrint<float const>);
    



    std::cout << "\n\n\nTest with a float array, and try to modify the content of the array, and print them !\n" << std::endl;
    float   floatArray[] = {42.0f, 12.0f, -1.0f};
    iter<float>(floatArray, 3, Incrementation);
    iter<float>(floatArray, 3, TemplatePrint<float>);

    
    return 0;
}