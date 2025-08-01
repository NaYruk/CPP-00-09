/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 14:09:07 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal( void );
        WrongAnimal( const WrongAnimal& copy );
        WrongAnimal& operator=( const WrongAnimal& copy );
        virtual ~WrongAnimal( void );

        virtual std::string    getType( void ) const;
        void           makeSound( void ) const;

    protected:
        std::string type;
};