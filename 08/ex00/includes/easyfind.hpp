/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:35:50 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/31 19:23:27 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <deque>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

template <typename T> 
typename T::iterator easyfind( T & container, int to_find )
{
    typename T::iterator it = std::find( container.begin(), container.end(), to_find );
    if (it == container.end()) {
        throw std::runtime_error( RED "No values found in the container !" RESET );
    }
    return it;
}