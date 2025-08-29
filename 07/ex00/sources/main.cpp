/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:36:16 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/29 20:01:43 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"

int main( void )
{
    {
        std::cout << "SUBJECT TEST :\n" << std::endl;
        
        int a = 2;
        int b = 3;
        
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    
        std::string c = "chaine1";
        std::string d = "chaine2";
        
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    
    {
        std::cout << "\n\n\nMY TEST :\n" << std::endl;

//      int     a = 2;
//      char    c = 'p';          //Error ! The template have one Type (T), cant give 2 different types !
//      swap<int>( a, c );

        double  nbr = 10.2;
        double  nbr2 = 58.4;
        
        ::swap<double>(nbr, nbr2);
        std::cout << "nbr = " << nbr << ", nbr2 = " << nbr2 << std::endl;
        std::cout << "min( nbr, nbr2 ) = " << ::min<double>( nbr, nbr2 ) << std::endl;
        std::cout << "max( nbr, nbr2 ) = " << ::max<double>( nbr, nbr2 ) << std::endl;
    }
    
    return 0;
}