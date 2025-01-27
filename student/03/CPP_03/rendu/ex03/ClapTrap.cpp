/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:43:38 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 19:40:23 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("Unnamed_Player"), _hit_points(10), _energy(10), _damage(0)
{
	std::cout << "Default constructor ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hit_points(10), _energy(10), _damage(0)
{
	std::cout << "Constructor ClapTrap called with name : " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &cpy)
{
	std::cout << "Copy constructor ClapTrap called" << std::endl;
	*this = cpy;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor of " << this->_name << " Called" << std::endl;
}


ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Assignement operator ClapTrap called" << std::endl;
	this->_damage = copy._damage;
	this->_hit_points = copy._hit_points;
	this->_energy = copy._energy;
	this->_name = copy._name;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hit_points > 0 && this->_energy > 0)
	{
		this->_energy--;
		std::cout << "ClapTrap " << this->_name << " attack " << target << " causing " << this->_damage << " damage, remaiming energy: " << this->_energy << std::endl;
	}
	else if (this->_hit_points <= 0)
		std::cout << "ClapTrap " << "How " << this->_name << " can attack someone he are dead" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " can't attack he doesnt have enought energy" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points > 0 && this->_hit_points >= (int)(amount))
	{
		this->_hit_points -= (int)(amount);
		std::cout << "ClapTrap " << this->_name << " be attacked and lost " << amount << " health (hit points), he has now " << this->_hit_points << " health." << std::endl;
		if (this->_hit_points <= 0)
		{
			std::cout << "ClapTrap " << this->_name << " losed to many health and died 😭" << std::endl;
			this->_hit_points = 0;
		}
	}
	else
		std::cout << "ClapTrap " << "Stop attacking " << this->_name << " he are already dead 😭" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points > 0 && this->_energy > 0)
	{
		this->_hit_points += (int)(amount);
		this->_energy--;
		std::cout << "ClapTrap " << this->_name << " repeared himself, restored: " << amount << " Current Health: " << this->_hit_points;
		std::cout << "ClapTrap " << " Remaiming energy: " << this->_energy << std::endl;
	}
	else if (this->_hit_points <= 0)
		std::cout << "ClapTrap " << this->_name << " can't repear himself cause he are already dead" << std::endl;
	else if (this->_energy == 0)
		std::cout << "ClapTrap " << this->_name << " can't repear himself cause he don't have enought energy" << std::endl;
}