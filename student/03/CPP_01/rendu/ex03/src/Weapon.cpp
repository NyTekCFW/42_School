/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 07:58:23 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:39:46 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string new_type): type(new_type)
{
}

Weapon::Weapon(void): type("")
{
}

void    Weapon::setType(std::string new_type)
{
    this->type = new_type;
}

const std::string& Weapon::getType(void)
{
    return (this->type);
}

Weapon::~Weapon(void)
{

}
