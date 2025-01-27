/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:45:17 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:45:17 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    public:
        DiamondTrap(void);
        DiamondTrap(const DiamondTrap &cpy);
        DiamondTrap(const std::string &name);
        DiamondTrap &operator=(const DiamondTrap &cpy);
        void attack(const std::string &target);
        void whoAmI(void);
        ~DiamondTrap(void);
    private:
        std::string _name;
};
