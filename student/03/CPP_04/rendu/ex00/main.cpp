/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:30 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 09:06:54 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog("Rex");
	const Animal* j2 = new Dog();
	const Animal* i2 = new Cat();
	const Animal* i = new Cat("Umy");

	std::cout << "\n--------Cat---------" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << i2->getType() << " " << std::endl;
	i->makeSound();
	i2->makeSound();
	delete i;
	delete i2;
	std::cout << "\n--------Dog---------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << j2->getType() << " " << std::endl;
	j->makeSound();
	j2->makeSound();
	delete j;
	delete j2;
	std::cout << "\n--------Animal---------" << std::endl;
	meta->makeSound();
	delete meta;

	std::cout << "\n--------Wrong Animal---------" << std::endl;

	const WrongAnimal* mwronganimal = new WrongAnimal();
	std::cout << mwronganimal->getType() << " " << std::endl;
	mwronganimal->makeSound();
	delete mwronganimal;

	std::cout << "\n--------Wrong Cat---------" << std::endl;
	const WrongAnimal* iwrongcat = new WrongCat();
	std::cout << iwrongcat->getType() << " " << std::endl;
	iwrongcat->makeSound();
	delete iwrongcat;

	return 0;
}