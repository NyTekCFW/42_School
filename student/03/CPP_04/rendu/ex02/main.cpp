/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:30 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 11:06:38 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define C 2
int main()
{
	int i = 0;
	//Animal test; //<-abstract test
	Animal* wild[C];
	// creer la moitier de C en tant que Dog et l autre moitier en tant que Cat
		// en les stockant dans le tableau Animal*
	for (i = 0; i < C; ++i)
	{
		if (i < C / 2)
			wild[i] = new Dog();
		else
			wild[i] = new Cat();
	}
	// Utilisation de makeSound() pour chaque Animal
	for (i = 0; i < C; ++i)
	{
		wild[i]->makeSound();
	}
	//convertie chaque animal en sa class respective via un dynamic_cast, et defini l idee 0
	for (i = 0; i < C; ++i)
	{
		if (i < C / 2)
			dynamic_cast<Dog *>(wild[i])->setBrain(0, "C'est l'heure de se promener!");
		else
			dynamic_cast<Cat *>(wild[i])->setBrain(0, "Donne moi a manger humain!");
	}
	//convertie chaque animal en sa class respective via un dynamic_cast, et montre l idee 0
	for (i = 0; i < C; ++i)
	{
		if (i < C / 2)
			std::cout << wild[i]->getType() << " say : "<< dynamic_cast<Dog *>(wild[i])->getBrain(0) << std::endl;
		else
			std::cout << wild[i]->getType() << " say : "<< dynamic_cast<Cat *>(wild[i])->getBrain(0) << std::endl;
	}
	std::cout << "\n--------Concrete Brain---------" << std::endl;
	Dog basic = Dog("Rex test");
	basic.setBrain(0, "j ai la flemme");
	
	Dog tmp = basic;
	std::cout << "tmp say : " << tmp.getBrain(0) << std::endl;
	std::cout << "basic say : " << basic.getBrain(0) << std::endl;
	//on supprime tout sa
	for (i = 0; i < C; ++i)
	{
		delete wild[i];
	}
	
	// retirer le virtual au destructor Animal va causer des erreur 
	//1 - de compilation dans ce projet
	//deleting object of polymorphic class type ‘Animal’ which has non-virtual destructor might cause
	//undefined behavior [-Werror=delete-non-virtual-dtor]
	// 2 - Ca peut entrainer un comportement imprevu lors de l execution vu que cela peut detruire des objet dans Animal toujours en cours d execution
	// dans les class Dog et Cat 
	return 0;
}