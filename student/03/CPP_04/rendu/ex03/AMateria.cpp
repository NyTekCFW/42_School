/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:35:19 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 11:12:33 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//Canon
AMateria::AMateria(const std::string& type): _type(type)
{
   /**/// std::cout << "AMateria::AMateria - Constructor type called. AMateria instance initialized with [" << type <<"]." << std::endl;
}

AMateria::AMateria(const AMateria& cpy)
{
    *this = cpy;
  /**///  std::cout << "AMateria::AMateria - Copy constructor called. A new AMateria was created from a copy." << std::endl;
}

const AMateria &AMateria::operator=(const AMateria &cpy)
{
    this->_type = cpy._type;
  /**///  std::cout << "AMateria::operator= - Assignment operator called. AMateria copied from another instance." << std::endl;
    return (*this);
}

AMateria::~AMateria(void)
{
   /**/// std::cout << "AMateria::~AMateria - Destructor called. AMateria instance is being destroyed." << std::endl;
}
//member
const std::string &AMateria::getType(void) const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Using AMateria on " << target.getName() << std::endl;
}

