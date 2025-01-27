/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:10:30 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 12:58:05 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

/* Conclusion CPP00->CPP04
CPP00:
Apprend a utiliser les fonction les plus basique du cpp comme std::string,
creer et detruire une class + mettre les variable de class en private et les utiliser via des
fonction style get/set
CPP01:
Apprend a utiliser (new / new[]) / (delete / delete[]).
les difference entre *, reference.
utiliser des fonction iostream/ fstream pour lire et exporter un fichier tout en remplacant un
character ou un mot specifique par autre chose.
Utiliser les switch.
CPP02:
Creer des class canon tout en apprennant a utiliser des float a virgule fix etc
(ces juste incroyable pour les huds/texte qui doivent se resize via des operation flottant
ca corrige les tremblement si la valeur final varie legerement via les calcul effectuer)
CPP03:
apprend l utilisation de class inherit et les base des class polymorphe + debut des virtuals
CPP04
apprend l utilisation des virtual et leur utiliter sur des destructor ou les interface / class abstract
*/


int main()
{
	AMateria* tmp = NULL;
	std::cout << "Making a new ICharacter with Character nammed 'User"  << std::endl;
	ICharacter* user = new Character("User");
	
	std::cout << "Making a new ICharacter with Character nammed 'Herve" << std::endl;
    ICharacter* herve = new Character("Herve");
	
	std::cout << "Making a new IMateriaSource with MateriaSource"  << std::endl;
    IMateriaSource* imat = new MateriaSource();
	
	std::cout << "Learning materias Cure & Ice"  << std::endl;
    imat->learnMateria(new Cure());
    imat->learnMateria(new Ice());

	std::cout << "Creating & equip Materia 'cure'"  << std::endl;
	tmp = imat->createMateria("cure");
    user->equip(tmp);
    
	std::cout << "Creating & equip Materia 'ice'"  << std::endl;
	tmp = imat->createMateria("ice");
    user->equip(tmp);
	
	std::cout << "Creating & equip a Fake Materia 'JAI_PAS_D_IDEE_DE_NOM'"  << std::endl;
	tmp = imat->createMateria("JAI_PAS_D_IDEE_DE_NOM");
    user->equip(tmp);
	
	std::cout << "Creating & equip a NULL Materia"  << std::endl;
	tmp = imat->createMateria("");
    user->equip(tmp);
	
	
	std::cout << "\nUsing Materia test"  << std::endl;
	std::cout << "Expected : * shoots an ice bolt at Herve *"  << std::endl;
	user->use(1, *herve); // will print: * shoots an ice bolt at herve *
	std::cout << "Expected : * heals herve's wounds *"  << std::endl;
    user->use(0, *herve); // will print: * heals herve's wounds *
	std::cout << "Expected : * shoots an ice bolt at User *"  << std::endl;
	user->use(1, *user); // will print: * shoots an ice bolt at User *
	std::cout << "Expected : * heals User's wounds *"  << std::endl;
    user->use(0, *user); // will print: * heals User's wounds *

	std::cout << "\nUnequip test"  << std::endl;
	std::cout << "Expected : no message with slot 0"  << std::endl;
	user->unequip(0);
	std::cout << "Expected : fail message with slot 3"  << std::endl;
	user->unequip(3);
	std::cout << "Expected : fail message with slot 10"  << std::endl;
	user->unequip(10);

	std::cout << "\nUse an Unequipped thing like slot 0"  << std::endl;
	std::cout << "Expected : fail message with slot 0"  << std::endl;
	user->use(0, *herve);
	
	std::cout << "\nRe-Equipping 'cure' and use"  << std::endl;
	tmp = imat->createMateria("cure");
    user->equip(tmp);
	std::cout << "Expected : * heals herve's wounds *"  << std::endl;
	user->use(0, *herve);
	
	std::cout << "\nRemoving everything"  << std::endl;
	delete herve;
    delete user;
    delete imat;

    return 0;
}
