/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 04:31:45 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:38:43 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(void): name("")
{
	std::cout << "Created Zombie." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name.c_str() << ": killed!" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
	std::cout << "name set : " << name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name.c_str() << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}