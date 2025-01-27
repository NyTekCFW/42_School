/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:35:31 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 11:47:56 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Character: public ICharacter
{
    public:
        //canon
        Character(void);
        Character(const std::string& username);
        Character(const Character& cpy);
        ~Character(void);
        const Character& operator=(const Character& cpy);
        //member
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        
    private:
        std::string _username;
        AMateria    *_slots[4];
};
