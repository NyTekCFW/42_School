/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:35:24 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 12:24:22 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): _username("default"), _slots()
{
    int i = 0;
    for (i = 0; i < 4; i++)
    {
       this->_slots[i] = NULL;
    }
  /**///  std::cout << "Character::Character - Default constructor called. Character instance initialized." << std::endl;
}

Character::Character(const std::string &username): _username(username), _slots()
{
    int i = 0;
    for (i = 0; i < 4; i++)
    {
       this->_slots[i] = NULL;
    }
 /**///   std::cout << "Character::Character - Constructor const std::string& called. Character instance initialized with [" << username <<"]." << std::endl;
}

Character::Character(const Character& cpy): _username(cpy._username)
{
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        if (cpy._slots[i])
            this->_slots[i] = cpy._slots[i]->clone();
        else
            this->_slots[i] = NULL;
    }
   /**/// std::cout << "Character::Character - Copy constructor called. A new Character was created from a copy." << std::endl;
}

const Character& Character::operator=(const Character& cpy)
{
    int i = 0;
    if (this != &cpy)
    {
        this->_username = cpy._username;
        for (i = 0; i < 4; i++)
        {
            if (this->_slots[i])
            {
                delete(this->_slots[i]);
                this->_slots[i] = NULL;
            }
            if (cpy._slots[i])
                this->_slots[i] = cpy._slots[i]->clone();
        }
    }
    
  /**///  std::cout << "Character::operator= - Assignment operator called. Character copied from another instance." << std::endl;
    return (*this);
}

Character::~Character(void)
{
    int i = 0;

    for (i = 0; i < 4; i++)
    {
        if (this->_slots[i])
        {
            delete(this->_slots[i]);
            this->_slots[i] = NULL;
        }
    }
  /**///  std::cout << "Character::~Character - Destructor called. Character instance is being destroyed." << std::endl;
}

void    Character::equip(AMateria *m)
{
    int i = 0;

    for (i = 0; i < 4; i++)
    {
        if (!this->_slots[i] && m && (m->getType() == "cure" || m->getType() == "ice"))
        {
            this->_slots[i] = m;
            return ;
        }
    }
    if (m)
        std::cout << "Character::equip() - Fail equiping Amateria [" << m->getType() << "]." << std::endl;
    else
        std::cout << "Character::equip() - Fail equiping Amateria m parameter is NULL." << std::endl;
}



void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        if (this->_slots[idx])
        {
           /**/// std::cout << this->_username << "'s unequip " << this->_slots[idx]->getType() << " materia at slot " << idx << " in inventory." << std::endl;
            delete(this->_slots[idx]);
            this->_slots[idx] = NULL;
            return ;
        }
    }
    std::cout << "Character::unequip() - Fail unequiping slot "<< idx <<"." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->_slots[idx])
    {
        this->_slots[idx]->use(target);
        return ;
    }
    std::cout << "Character::use - Fail use slot [" << idx << "] with "<< target.getName() <<"." << std::endl;
}

std::string const & Character::getName() const
{
    return (this->_username);
}
