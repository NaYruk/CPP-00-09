/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/16 08:53:38 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

void    check_result(bool result, Point a, Point b, Point c, Point point)
{
    if (result == true)
        std::cout << "for a = " << a << " b = " << b << " c = " << c << " and Point = " << point << " The point is in the triangle ! ✅" << std::endl;
    else
        std::cout << "for a = " << a << " b = " << b << " c = " << c << " and Point = " << point << " The point is not in the triangle ! ❌" << std::endl;
    return ;
}

int main ( void )
{
    bool    result;

    Point   a( 1, 2 );
    Point   b( 3, 5 );
    Point   c( 7, 3 );

    Point   point( 3, 3.5 );
    result = bsp( a, b, c, point );
    check_result(result, a, b, c, point);
    
    return (0);
}
