/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/19 16:38:48 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

// Basic Constructor for initialize the value of the fixed-point number to 0
Fixed::Fixed( void ) : _NbrValue(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Overload Constructor for convert an int Nbr to a fixed-point number
// For convert to a fixed-point number, we need to multiply the Nbr by 2^n, where n is the nbr of bits for the fractionnal part.
// 1 << 8 shifts the binary point to the right : 1 -> 1000000 = 256 = 2^8.
// nbr * 256 = nbr convert to a fixed-point number with 8 bits reserved for the fractionnal part.
// (this is for _NbrBits = 8)
Fixed::Fixed( const int nbr )
{
    std::cout << "Int constructor called" << std::endl;
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
    std::cout << "Float constructor called" << std::endl;
    this->_NbrValue = roundf(nbr * (1 << this->_NbrBits));
    return ;
}

// Overload Constructor for create a constructor of copy
Fixed::Fixed( const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
    return ;
}

// Overload of operator, = for copy an Fixed class
Fixed &Fixed::operator=( const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
    float convert_float = static_cast<float>(fixed.getRawBits()) / (1 << 8);
    
    flux << convert_float;
    return (flux);
}


// Destructor of the Fixed Class.
Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
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
