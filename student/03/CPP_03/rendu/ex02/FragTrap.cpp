/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:44:29 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 19:43:50 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
    std::cout << "FragTrap Default Constructor called" << std::endl;
    this->_hit_points = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap(const FragTrap &cpy): ClapTrap(cpy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FragTrap Constructor for the name " << this->_name << " called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Deconstructor for " << this->_name << " called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &cpy)
{
	this->_name = cpy._name;
	this->_hit_points = cpy._hit_points;
	this->_energy = cpy._energy;
	this->_damage = cpy._damage;
	std::cout << "FragTrap Assignation operator called" << std::endl;
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hit_points <= 0)
		std::cout << "FragTrap " << "Cannot high five because: FragTrap " << this->_name << " is dead." << std::endl;
	else
		std::cout << "FragTrap " << this->_name << ": want a high fives?\nHere you go." << std::endl;
}