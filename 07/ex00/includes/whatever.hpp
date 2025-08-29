/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:36:21 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/29 21:15:17 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template< typename T >
void    swap( T & x, T & y )
{
    T tmp;

    tmp = y;
    y = x;
    x = tmp;
}

template< typename T >
T const &   min( T const & x, T const & y )
{
    if (x == y)
        return y;
    else if (x < y)
        return x;
    else
        return y;
}

template< typename T >
T const &   max( T const & x, T const & y )
{
    if (x == y)
        return y;
    else if (x > y)
        return x;
    else
        return y;
}