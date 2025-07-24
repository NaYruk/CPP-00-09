/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:24:04 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/24 16:57:48 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"

int main()
{
	std::cout << "SUBJECT TESTS" << std::endl;
	std::cout << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "MY TESTS" << std::endl;
	std::cout << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		
		ICharacter* me = new Character("Melvin");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->equip(tmp);
		
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);
		me->unequip(3);
		me->unequip(0);
		
		ICharacter* Maxou = new Character("Melvin");
		me->use(0, *Maxou);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->use(0, *Maxou);
		
		delete me;
		delete Maxou;
		delete src;
	}
	
	return 0;
}