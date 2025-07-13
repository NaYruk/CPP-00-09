/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 18:33:41 by mmilliot         ###   ########.fr       */
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

        std::string    getType( void ) const;
        void           makeSound( void ) const;

    protected:
        std::string type;
};