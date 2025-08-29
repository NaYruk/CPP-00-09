/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:36:21 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/29 20:44:26 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template< typename A, typename F >
void    iter( A * array, int length, F function )
{
    if (!array)
        return ;
        
    for (int i = 0; i < length; i++) {
        function( array[i] );
    }
}