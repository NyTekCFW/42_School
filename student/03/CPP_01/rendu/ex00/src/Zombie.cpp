/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 05:40:05 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:38:19 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(void): _name("")
{
	std::cout << "Zombie created." << std::endl;
}

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "Zombie " << this->_name << " created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name.c_str() << ": killed!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name.c_str() << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}