/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:44:08 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 19:44:41 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
    private:
        bool    _gate;
    public:
    ScavTrap &operator=(const ScavTrap &src);
    void attack(const std::string &target);
    void guardGate(void);
    ScavTrap(void);
    ScavTrap(const ScavTrap &copy);
    ScavTrap(const std::string& name);
    ~ScavTrap(void);
};