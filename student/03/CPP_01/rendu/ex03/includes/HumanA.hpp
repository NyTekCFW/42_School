/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 07:58:57 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:39:10 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
	void	setWeapon(Weapon c);
	void	attack(void);
	HumanA(std::string name, Weapon& club);
	~HumanA(void);
private:
	std::string	_name;
	Weapon		&wpn;
};

#endif