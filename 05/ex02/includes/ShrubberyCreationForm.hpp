/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:24:07 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/21 19:24:10 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	//Canonical
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm& copy );
		ShrubberyCreationForm&	operator=( ShrubberyCreationForm& copy );
		~ShrubberyCreationForm( void );

	private:
		std::string	target;
};
