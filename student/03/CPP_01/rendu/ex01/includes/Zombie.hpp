/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 04:31:48 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:38:29 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

class Zombie
{
public:
	void	set_name(std::string name);
	void	announce(void);
	Zombie(void);
	~Zombie(void);
private:
	std::string name;
};

Zombie	*zombieHorde( int N, std::string name );
#endif