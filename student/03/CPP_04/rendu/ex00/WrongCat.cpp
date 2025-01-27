/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:39 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 08:54:26 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat from WrongAnimal : default constructor." << std::endl;
}

WrongCat::WrongCat(const std::string &type): WrongAnimal(type)
{
    std::cout << "WrongCat from WrongAnimal : Constructor created." << std::endl;
}

WrongCat::WrongCat(const WrongCat& cpy): WrongAnimal(cpy)
{
    *this = cpy;
    std::cout << "WrongCat from WrongAnimal " << WrongAnimal::_type << " copied." << std::endl;
}

const WrongCat &WrongCat::operator=(const WrongCat& cpy)
{
   WrongAnimal::operator=(cpy);
   std::cout << "WrongCat from WrongAnimal : Assignment operator for called." << std::endl;
   return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat from WrongAnimal Destructor Called." << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat From WrongAnimal : Wrong Meow!" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const WrongCat & c)
{
    o << c.getType();
    return (o);
}