/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:27:17 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/22 16:12:11 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		//Canonical
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm& copy );
		PresidentialPardonForm&	operator=( const PresidentialPardonForm& copy ); 
		~PresidentialPardonForm( void );
	
		//makeAction : Execute the action of Shrubbery
		//Execute : Execute the method of AForm
		virtual void	makeAction( void ) const;
		void	execute( Bureaucrat const & executor ) const;
		
	private:
		std::string target;
};