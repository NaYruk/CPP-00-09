/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/10 19:34:14 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

// Default constructor that initializes points x and y has 0.
Point::Point( void ) : x(0), y(0) {}

// Constructor that initializes points x and y to the desired values.
Point::Point( const float init_x, const float init_y ) : x(init_x), y(init_y) {}

// Constructor of copy.
Point::Point( const Point &copy ) : x(copy.x), y(copy.y) {}

// Overload of '=' operator do nothing because x and y is const.
Point   &Point::operator=( const Point &copy )
{
    (void)copy;
    return (*this);
}

// Destructor.
Point::~Point( void ) {}

// Function for get the Fixed value of the x variable.
Fixed   Point::getX( void ) const
{
    return (this->x);
}

// Function for get the Fixed value of the y variable.
Fixed   Point::getY( void ) const
{
    return (this->y);
}


// Function for get the Float value of the x variable.
float   Point::getFloatX( void ) const
{
    return (this->x.toFloat());
}

// Function for get the Float value of the y variable.
float   Point::getFloatY( void ) const
{
    return (this->y.toFloat());
}
        
// overload of << operator.
std::ostream    &operator<<( std::ostream &flux, const Point &point)
{
    flux << "( " << point.getFloatX() << ", " << point.getFloatY() << " )";
    return (flux);
}