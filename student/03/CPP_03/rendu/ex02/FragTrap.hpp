/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:44:32 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 19:43:10 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(const FragTrap& cpy);
        FragTrap(const std::string& name);
        ~FragTrap(void);
        FragTrap &operator=(const FragTrap &cpy);
        void    highFivesGuys(void);
    private:
};