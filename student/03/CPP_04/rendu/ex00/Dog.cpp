/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:24 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 09:11:30 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//canon
Dog::Dog(void): Animal("Dog")
{
    std::cout << "Dog from Animal default constructor." << std::endl;
}

Dog::Dog(const std::string &type): Animal(type)
{
    std::cout << "Dog from  Animal Constructor " << Animal::_type << " created." << std::endl;
}

Dog::Dog(const Dog& cpy): Animal(cpy)
{
    *this = cpy;
    std::cout << "Dog from Animal: " << Animal::_type << " copied." << std::endl;
}

const Dog &Dog::operator=(const Dog& cpy)
{
   Animal::operator=(cpy);
   std::cout << "Assignment operator for Dog from Animal " << Animal::_type << " called." << std::endl;
   return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog from Animal " << Animal::_type << " Destructor Called." << std::endl;
}
//member

void Dog::makeSound() const
{
    std::cout << "Dog From Animal " << Animal::_type << " : Bark!" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Dog & c)
{
    o << c.getType();
    return (o);
}