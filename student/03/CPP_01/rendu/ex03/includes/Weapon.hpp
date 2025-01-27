/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 07:58:23 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:39:16 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>

class Weapon
{
public:
	Weapon(void);
    Weapon(std::string new_type);
    ~Weapon(void);
    void setType(std::string new_type);
    const std::string& getType(void);
private:
    std::string type;
};

#endif