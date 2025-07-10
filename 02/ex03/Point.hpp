/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/10 19:06:56 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Fixed.hpp"

class Point
{
    public:
        Point( void );
        Point( const float init_x, const float init_y );
        Point( const Point &copy );
        Point &operator=( const Point &copy ); 
        ~Point( void );

        Fixed   getX( void ) const;
        Fixed   getY( void ) const;

        float   getFloatX( void ) const;
        float   getFloatY( void ) const;
        
    private:
        const Fixed x;
        const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

std::ostream &operator<<(std::ostream &flux, const Point &point);