/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 18:35:31 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Animal.hpp"

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
};