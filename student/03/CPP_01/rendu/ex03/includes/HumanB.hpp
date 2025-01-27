/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 07:59:00 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:39:12 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
	void	setWeapon(Weapon& c);
	void	attack(void);
	HumanB(std::string n);
	~HumanB(void);
	
private:
	std::string	_name;
	Weapon*		wpn;
};

#endif