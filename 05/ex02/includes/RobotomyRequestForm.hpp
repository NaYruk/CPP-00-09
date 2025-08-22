/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:53:23 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/22 16:12:26 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"

#pragma once

class RobotomyRequestForm : public AForm
{
	public:
		//Canonical
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& copy );
		RobotomyRequestForm&	operator=( const RobotomyRequestForm& copy );
		~RobotomyRequestForm( void );
	
		//makeAction : Execute the action of Shrubbery
		//Execute : Execute the method of AForm
		virtual void	makeAction( void ) const;
		void	execute( Bureaucrat const & executor ) const;
		
	private:
		std::string	target;
};

