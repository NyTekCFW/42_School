/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:44:35 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:44:35 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

static void fragtrap_jean_kevin(void)
{
	int	a = 0;
	FragTrap jean_kevin("jean_kevin");

	jean_kevin.attack("bot 1");
	jean_kevin.attack("bot 2");
	jean_kevin.attack("bot 3");
	jean_kevin.attack("bot 4");
	jean_kevin.highFivesGuys();
	while (a < 10)
	{
		jean_kevin.takeDamage(20);
		jean_kevin.beRepaired(10);
		a++;
	}
	jean_kevin.takeDamage(1);
	jean_kevin.highFivesGuys();
}

int main(void)
{
	fragtrap_jean_kevin();
	return (0);
}
