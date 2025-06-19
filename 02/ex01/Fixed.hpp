/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/19 15:57:52 by mmilliot         ###   ########.fr       */
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

    private:
        int                 _NbrValue;
        static const int    _NbrBits = 8;
};

std::ostream &operator<<(std::ostream &flux, const Fixed &fixed);