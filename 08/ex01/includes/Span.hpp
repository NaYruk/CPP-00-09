/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:09:17 by mmilliot          #+#    #+#             */
/*   Updated: 2025/09/09 04:26:02 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <ctime>
#include <algorithm>

class Span 
{
    public:
        // Canonical
        Span( void );
        Span( unsigned int N );
        Span ( Span const & copy );
        Span &  operator=( Span const & copy );
        ~Span( void );

        //AddNumber Function : Add a single number to the Span
        void    addNumber( int const toAdd );

        //AddNumberRange : Add a Range of number to the Span
        void    addRange( std::vector<int>::iterator first, std::vector<int>::iterator last );

        
        //shortestSpan Function : Find out the shortest span(distance) between all the numbers stored !
        int     shortestSpan( void ) const;
        
        //longestSpan Function : Find out the longest span(distance) between all the numbers stored !
        int     longestSpan( void ) const;
         
        //Utils for print the container
        void    printSpan( void );
        
    private:
        std::vector<int> _VecSpan;
        unsigned int     _sizeMax;
};