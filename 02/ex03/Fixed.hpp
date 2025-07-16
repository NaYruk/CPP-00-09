/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/16 08:13:29 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#pragma once

class Fixed
{
    public:
        Fixed( void );
        Fixed( const int nbr );
        Fixed( const float nbr);
        Fixed( const Fixed &copy );
        Fixed &operator=( const Fixed &copy);
        ~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
        
        float   toFloat( void ) const;
        int     toInt( void ) const;

        bool    operator>( const Fixed &other) const;
        bool    operator<( const Fixed &other) const;
        bool    operator>=( const Fixed &other) const;
        bool    operator<=( const Fixed &other) const;
        bool    operator==( const Fixed &other) const;
        bool    operator!=( const Fixed &other) const;

        float     operator+( const Fixed &other) const;
        float     operator-( const Fixed &other) const;
        float     operator*( const Fixed &other) const;
        float     operator/( const Fixed &other) const;

        Fixed   &operator++( void );
        Fixed   operator++( int Nbr );
        Fixed   &operator--( void );
        Fixed   operator--( int Nbr );


        static Fixed min(Fixed &nbr1, Fixed &nbr2);
        static Fixed min(const Fixed &nbr1, const Fixed &nbr2);
        
        static Fixed max(Fixed &nbr1, Fixed &nbr2);
        static Fixed max(const Fixed &nbr1, const Fixed &nbr2);

    private:
        int                 _NbrValue;
        static const int    _NbrBits = 8;
};

std::ostream &operator<<(std::ostream &flux, const Fixed &fixed);