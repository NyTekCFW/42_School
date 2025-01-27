/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 07:59:00 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:39:40 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string n) : _name(n), wpn(NULL)
{
	std::cout << "HumanB " << this->_name << " created with no weapon" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->_name << " destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon& c)
{
	this->wpn = &c;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << wpn->getType() << std::endl;
}