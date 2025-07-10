/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/10 19:35:49 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

// Vector: A(x1, y1) and B(x2, y2) -> Vector AB = (x2 - x1, y2 - y1). This represents a length and a direction.
// Cross Product: For 2 vectors: u = (ux, uy) and v = (vx, vy), Cross Product = u * v = (ux * vy) - (uy * vx).
    // IF POSITIVE, u is in the counterclockwise direction relative to v.
    // IF NEGATIVE, u is in the clockwise direction relative to v.
    // IF ZERO, the two vectors are collinear, i.e., they lie on the same line.
// THUS, TO CHECK IF A POINT IS INSIDE A TRIANGLE, we need: Vec AP * Vec AB, Vec BP * Vec BC, Vec CP * Vec CA.
// AND CHECK IF the three cross products have the same sign.

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Point   vecAP( point.getX() - a.getX(), point.getY() - a.getY() );
    Point   vecAB( b.getX() - a.getX(), b.getY() - a.getY() );
    
    Fixed   d1 = vecAP.getX() * vecAB.getY() - vecAP.getY() * vecAB.getX();
    
    Point   vecBP( point.getX() - b.getX(), point.getY() - b.getY() );
    Point   vecBC( c.getX() - b.getX(), c.getY() - b.getY() );
    
    Fixed   d2 = vecBP.getX() * vecBC.getY() - vecBP.getY() * vecBC.getX();

    Point   vecCP( point.getX() - c.getX(), point.getY() - c.getY() );
    Point   vecCA( a.getX() - c.getX(), a.getY() - c.getY() );

    Fixed   d3 = vecCP.getX() * vecCA.getY() - vecCP.getY() * vecCA.getX();


    Fixed   zero(0);
    if ( d1 == zero || d2 == zero || d3 == zero )
        return (false);

    if ( (d1 > zero && d2 > zero && d3 > zero) || (d1 < zero && d2 < zero && d3 < zero) )
        return (true);
    return (false);
}