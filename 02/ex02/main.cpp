/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/19 18:40:43 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

int main ( void )
{
    {
        Fixed a(10);
        Fixed b(20);
    
        if (a < b)
            std::cout << a << " < " << b << std::endl;
        if (a <= b)
            std::cout << a << " <= " << b << std::endl;
        if (a > b)
            std::cout << a << " > " << b << std::endl;
        if (a >= b)
            std::cout << a << " >= " << b << std::endl;
        if (a == b)
             std::cout << a << " == " << b << std::endl;
        if (a != b)
             std::cout << a << " != " << b << std::endl;
        
        std::cout << std::endl;
    
        std::cout << "a = " << a << " b = " << b << " a + b = " << a + b << std::endl;
        std::cout << "a = " << a << " b = " << b << " a - b = " << a - b << std::endl;
        std::cout << "a = " << a << " b = " << b << " a * b = " << a * b << std::endl;
        std::cout << "a = " << a << " b = " << b << " a / b = " << a / b << std::endl;
    
         std::cout << std::endl;
    
        std::cout << "a = " << a << std::endl;
        std::cout << "++a = " << ++a << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "a++ = " << a++ << std::endl;
        std::cout << "a = " << a << std::endl;
        
        std::cout << std::endl;
        
        std::cout << Fixed::max( a, b ) << std::endl;
        std::cout << Fixed::min( a, b ) << std::endl;
    }
    

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    

    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        
        std::cout << b << std::endl;
        
        std::cout << Fixed::max( a, b ) << std::endl;
    }
    
    return 0;
}