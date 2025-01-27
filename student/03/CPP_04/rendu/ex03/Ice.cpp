/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:35:39 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 14:59:08 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
   /**/// std::cout << "Ice::Ice - Default constructor called. Ice instance initialized." << std::endl;
}

Ice::Ice(const Ice& cpy): AMateria(cpy)
{
  /**///  std::cout << "Ice::Ice - Copy constructor called. A new Ice was created from a copy." << std::endl;
}

Ice::~Ice(void)
{
   /**/// std::cout << "Ice::~Ice - Destructor called. Ice instance is being destroyed." << std::endl;
}

const Ice& Ice::operator=(const Ice& cpy)
{
    this->_type = cpy._type;
  /**///  std::cout << "Ice::operator= - Assignment operator called. Ice copied from another instance." << std::endl;
    return (*this);
}

AMateria *Ice::clone(void) const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}