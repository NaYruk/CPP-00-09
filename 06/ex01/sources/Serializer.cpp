/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:01:51 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/28 19:33:39 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

//Canonical
Serializer::Serializer( void ) {}

Serializer::Serializer( Serializer const & copy ) { (void)copy; }

Serializer& Serializer::operator=( Serializer const & copy ) { (void)copy; return *this; }

Serializer::~Serializer( void ) {}




uintptr_t   Serializer::serialize( Data* ptr )
{
    if (ptr)
        return reinterpret_cast<uintptr_t>(ptr);
        
     std::cerr << RED << "The pointer is NULL !" << RESET << std::endl;
    return 0;
}

Data*   Serializer::deserialize( uintptr_t raw )
{
    if (raw)
        return reinterpret_cast<Data *>(raw);
    
    std::cerr << RED << "The uintptr_t is NULL !" << RESET << std::endl;
    return NULL;
}