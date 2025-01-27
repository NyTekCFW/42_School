/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:45:27 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:45:27 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

static void diamondtrap_jean_kevin(void)
{
	int	a = 0;
	DiamondTrap jean_kevin("jean_kevin");

	jean_kevin.attack("bot 1");
	jean_kevin.attack("bot 2");
	jean_kevin.attack("bot 3");
	jean_kevin.attack("bot 4");
	jean_kevin.guardGate();
	jean_kevin.highFivesGuys();
	jean_kevin.whoAmI();
	while (a < 10)
	{
		jean_kevin.takeDamage(20);
		jean_kevin.beRepaired(10);
		a++;
	}
	jean_kevin.takeDamage(1);
	jean_kevin.guardGate();
	jean_kevin.highFivesGuys();
	jean_kevin.whoAmI();
}

int main(void)
{
	diamondtrap_jean_kevin();
	return (0);
}
