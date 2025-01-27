/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:44:03 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:44:03 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static void scavtrap_jean_kevin(void)
{
	int	a = 0;
	ScavTrap jean_kevin("jean_kevin");

	jean_kevin.attack("bot 1");
	jean_kevin.attack("bot 2");
	jean_kevin.attack("bot 3");
	jean_kevin.attack("bot 4");
	jean_kevin.guardGate();
	while (a < 10)
	{
		jean_kevin.takeDamage(20);
		jean_kevin.beRepaired(10);
		a++;
	}
	jean_kevin.takeDamage(1);
	jean_kevin.guardGate();
}

int main(void)
{
	scavtrap_jean_kevin();
	return (0);
}
