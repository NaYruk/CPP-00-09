/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:12:10 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/28 19:38:36 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main( void )
{
    Data    data;

    data.c = 'a';
    data.nbr = 42;
    data.str = "Im a string !";
    
    std::cout << "BEFORE SERIALIZE" << std::endl;
    std::cout << "Adresse : " << &data << std::endl; 
    std::cout << "char : " << data.c << std::endl;
    std::cout << "int : " << data.nbr << std::endl;
    std::cout << "string : " << data.str << std::endl;
    
    uintptr_t   raw = Serializer::serialize( &data );
    Data *result = Serializer::deserialize( raw );
    
    std::cout << "\n\nAFTER DESERIALIZE :" << std::endl;
    std::cout << "Adresse : " << result << std::endl; 
    std::cout << "char : " << result->c << std::endl;
    std::cout << "int : " << result->nbr << std::endl;
    std::cout << "string : " << result->str << std::endl;
    
    return 0;
}