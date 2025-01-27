/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 05:37:24 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:38:05 by lchiva           ###   ########.fr       */
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
		void	announce(void);
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
private:
		std::string _name;
};

Zombie *newZombie(std::string name);
void 	randomChump( std::string name );

#endif