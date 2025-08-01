/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 15:16:44 by marcmilliot      ###   ########.fr       */
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
        virtual ~Animal( void );

        virtual std::string    getType( void ) const;
        virtual void           makeSound( void ) const;
        
        virtual void           addIdea(const std::string& idea);
        virtual void           showIdeas(void) const;

    protected:
        std::string type;
};