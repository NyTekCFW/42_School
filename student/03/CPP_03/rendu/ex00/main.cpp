/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:43:45 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:43:45 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void claptrap_jean_kevin(void)
{
	int	a = 0;
	ClapTrap jean_kevin("jean_kevin");

	jean_kevin.attack("bot 1");
	jean_kevin.attack("bot 2");
	jean_kevin.attack("bot 3");
	jean_kevin.attack("bot 4");
	while (a < 10)
	{
		jean_kevin.takeDamage(2);
		jean_kevin.beRepaired(1);
		a++;
	}
	jean_kevin.takeDamage(1);
}

int main(void)
{
	claptrap_jean_kevin();
	return (0);
}
