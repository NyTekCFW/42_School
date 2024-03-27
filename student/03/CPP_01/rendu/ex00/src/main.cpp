/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 05:20:07 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/27 06:10:27 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
	Zombie *zm;
	randomChump("SVSC_Member(s)");
	randomChump("NyTekCFW");
	randomChump("ZenaxFR");
	randomChump("Zeam");
	randomChump("Lowell");
	randomChump("Curly");
	zm = newZombie("Support Misakii");
	zm->announce();
	delete(zm);
}
