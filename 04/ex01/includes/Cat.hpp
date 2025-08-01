/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 15:20:40 by marcmilliot      ###   ########.fr       */
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
        
        void        makeSound( void ) const;  
        virtual void        addIdea(const std::string& line);
        virtual void        showIdeas(void) const;
    
    private:
        Brain*      brain;
};