/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:24:07 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/22 16:25:11 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"

#pragma once

class	ShrubberyCreationForm : public AForm
{
	public:
		//Canonical
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm& copy );
		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& copy );
		virtual ~ShrubberyCreationForm( void );
		
		//makeAction : Execute the action of Shrubbery
		//Execute : Execute the method of AForm
		virtual void	makeAction( void ) const;
		void	execute( Bureaucrat const & executor ) const;

	private:
		std::string	target;
};
