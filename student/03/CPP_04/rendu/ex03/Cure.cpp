/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:35:34 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 14:58:54 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
   /**/// std::cout << "Cure::Cure - Default constructor called. Cure instance initialized." << std::endl;
}

Cure::Cure(const Cure& cpy): AMateria(cpy)
{
   /**/// std::cout << "Cure::Cure - Copy constructor called. A new Cure was created from a copy." << std::endl;
}

Cure::~Cure(void)
{
  /**///  std::cout << "Cure::~Cure - Destructor called. Cure instance is being destroyed." << std::endl;
}

const Cure& Cure::operator=(const Cure& cpy)
{
    this->_type = cpy._type;
  /**///  std::cout << "Cure::operator= - Assignment operator called. Cure copied from another instance." << std::endl;
    return (*this);
}

AMateria *Cure::clone(void) const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}