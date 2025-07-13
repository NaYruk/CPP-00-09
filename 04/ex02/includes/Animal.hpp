/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 22:21:58 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
    public:
        Animal( void );
        Animal( const Animal& copy );
        Animal& operator=( const Animal& copy );
        virtual ~Animal( void ) = 0;    //pure virtual

        virtual std::string    getType( void ) const;
        virtual void           makeSound( void ) const;

    protected:
        std::string type;
};