/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/19 18:51:07 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

// Basic Constructor for initialize the value of the fixed-point number to 0
Fixed::Fixed( void ) : _NbrValue(0)
{
    return ;
}

// Overload Constructor for convert an int Nbr to a fixed-point number
// For convert to a fixed-point number, we need to multiply the Nbr by 2^n, where n is the nbr of bits for the fractionnal part.
// 1 << 8 shifts the binary point to the right : 1 -> 1000000 = 256 = 2^8.
// nbr * 256 = nbr convert to a fixed-point number with 8 bits reserved for the fractionnal part.
// (this is for _NbrBits = 8)
Fixed::Fixed( const int nbr )
{
    this->_NbrValue = nbr * (1 << this->_NbrBits);
    return ;
}

// Overload Constructor for convert an float Nbr to a fixed-point number
// For convert to a fixed-point number, we need to multiply the Nbr by 2^n, where n is the nbr of bits for the fractionnal part.
// 1 << 8 shifts the binary point to the right : 1 -> 1000000 = 256 = 2^8.
// nbr * 256 = nbr convert to a fixed-point number with 8 bits reserved for the fractionnal part.
// (this is for _NbrBits = 8)
Fixed::Fixed( const float nbr )
{
    this->_NbrValue = roundf(nbr * (1 << this->_NbrBits));
    return ;
}

// Overload Constructor for create a constructor of copy
Fixed::Fixed( const Fixed &copy)
{
    *this = copy;
    return ;
}

// Overload of operator, = for copy an Fixed class
Fixed &Fixed::operator=( const Fixed &copy)
{
    if (this != &copy)
    {
        this->_NbrValue = copy.getRawBits();
    }
    return (*this);
}

// Overload of operator, << for print a conversion of a fixed-point number to a float number.
// For convert to a float, we need to divide the fixed-point Nbr by 2^n, where n is the nbr of bits for the fractionnal part.
// 1 << 8 shifts the binary point to the right : 1 -> 1000000 = 256 = 2^8.
// nbr / 256 = nbr convert to float.
// (this is for _NbrBits = 8)
std::ostream &operator<<(std::ostream &flux, const Fixed &fixed)
{
    flux << fixed.toFloat();
    return (flux);
}


// Destructor of the Fixed Class.
Fixed::~Fixed( void )
{
    return ;
}


// Getter for return the fixed-point number (private attribute of the class Fixed).
int	Fixed::getRawBits( void ) const
{
	return (this->_NbrValue);
}

// Setter for set the fixed-point number (private attribute of the class Fixed).
void Fixed::setRawBits( int const raw )
{
	this->_NbrValue = raw;
}



// Function for convert a Fixed-point number to a Float.
float   Fixed::toFloat( void ) const
{
    return (static_cast<float>(this->_NbrValue) / (1 << this->_NbrBits));
}

// Function for convert a Fixed-point number to an Int.
int     Fixed::toInt( void ) const
{
    return (this->_NbrValue / (1 << this->_NbrBits));
}


// Overload of > operator
bool    Fixed::operator>( const Fixed &other) const
{
    return (this->toFloat() > other.toFloat());
}

// Overload of < operator
bool    Fixed::operator<( const Fixed &other) const
{
    return (this->toFloat() < other.toFloat());
}

// Overload of >= operator
bool    Fixed::operator>=( const Fixed &other) const
{
    return (this->toFloat() >= other.toFloat());
}

// Overload of <= operator
bool    Fixed::operator<=( const Fixed &other) const
{
    return (this->toFloat() <= other.toFloat());
}

// Overload of == operator
bool    Fixed::operator==( const Fixed &other) const
{
    return (this->toFloat() == other.toFloat());
}

// Overload of != operator
bool    Fixed::operator!=( const Fixed &other) const
{
    return (this->toFloat() != other.toFloat());
}



// Overload of + operator
float     Fixed::operator+( const Fixed &other) const
{
   return (this->toFloat() + other.toFloat());
}

// Overload of - operator
float     Fixed::operator-( const Fixed &other) const
{
    return (this->toFloat() - other.toFloat());
}

// Overload of * operator
float     Fixed::operator*( const Fixed &other) const
{
    return (this->toFloat() * other.toFloat());
}

// Overload of / operator
float     Fixed::operator/( const Fixed &other) const
{
    return (this->toFloat() / other.toFloat());
}



// Overload of ++ prefix operator
Fixed   &Fixed::operator++( void )
{
    ++(this->_NbrValue);
    return (*this);
}

// Overload of ++ suffix operator
Fixed   Fixed::operator++( int Nbr )
{
    Fixed temp(*this);
    
    ++(this->_NbrValue);
    return (temp);
}

// Overload of -- prefix operator
Fixed   &Fixed::operator--( void )
{
    --(this->_NbrValue);
    return (*this);
}

// Overload of ++ suffix operator
Fixed   Fixed::operator--( int Nbr )
{
    Fixed temp(*this);
    
    --(this->_NbrValue);
    return (temp);
}



// Overload of Function min (return the minimum number)
Fixed Fixed::min(Fixed &nbr1, Fixed &nbr2)
{
    if (nbr1 < nbr2)
        return (nbr1);
    else
        return (nbr2);
}

// Overload of Function min (return the minimum number)
Fixed Fixed::min(const Fixed &nbr1, const Fixed &nbr2)
{
    if (nbr1 < nbr2)
        return (nbr1);
    else
        return (nbr2);
}

// Overload of Function max (return the max number)
Fixed Fixed::max(Fixed &nbr1, Fixed &nbr2)
{
    if (nbr1 > nbr2)
        return (nbr1);
    else
        return (nbr2);
}

// Overload of Function max (return the max number)
Fixed Fixed::max(const Fixed &nbr1, const Fixed &nbr2)
{
    if (nbr1 > nbr2)
        return (nbr1);
    else
        return (nbr2);
}