/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 19:55:34 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : public Animal
{
    public:
        Cat( void );
        Cat( const Cat& copy );
        Cat& operator=( const Cat& copy );
        virtual ~Cat( void );

        std::string    getType( void ) const;
        void           makeSound( void ) const;   
    
    private:
        std::string type;
        Brain*      brain;
};