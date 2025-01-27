/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:44:11 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 19:42:23 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap(), _gate(false)
{
	this->_hit_points = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy), _gate(copy._gate)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name), _gate(false)
{
	this->_hit_points = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "ScavTrap Constructor with the name " << this->_name << " called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Deconstructor for " << this->_name << " called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy = src._energy;
	this->_damage = src._damage;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hit_points > 0 && this->_energy > 0)
	{
		this->_energy--;
		std::cout << "ScavTrap " << this->_name << " attack " << target << " causing " << this->_damage << " damage, remaiming energy: " << this->_energy << std::endl;
	}
	else if (this->_hit_points <= 0)
		std::cout << "ScavTrap How " << this->_name << " can attack someone he are dead" << std::endl;
	else
		std::cout << "ScavTrap " <<this->_name << " can't attack he doesnt have enought energy" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hit_points <= 0)
		std::cout << "ScavTrap " << "Cannot switch to guarding the gate because: ScavTrap " << this->_name << " is dead." << std::endl;
	else if (!this->_gate)
	{
		this->_gate = true;
		std::cout << "ScavTrap " << this->_name << " is now guarding the gate." << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is already guarding the gate." << std::endl;
}
