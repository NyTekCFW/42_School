/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:17 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 09:11:22 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//canon
Cat::Cat(void): Animal("Cat")
{
    std::cout << "Cat from Animal default constructor." << std::endl;
}

Cat::Cat(const std::string &type): Animal(type)
{
    std::cout << "Cat from  Animal Constructor " << Animal::_type << " created." << std::endl;
}

Cat::Cat(const Cat& cpy): Animal(cpy)
{
    *this = cpy;
    std::cout << "Cat from Animal: " << Animal::_type << " copied." << std::endl;
}

const Cat &Cat::operator=(const Cat& cpy)
{
   Animal::operator=(cpy);
   std::cout << "Assignment operator for Cat from Animal " << Animal::_type << " called." << std::endl;
   return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat from Animal " << Animal::_type << " Destructor Called." << std::endl;
}
//member

void Cat::makeSound() const
{
    std::cout << "Cat From Animal " << Animal::_type << " : Meow!" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Cat & c)
{
    o << c.getType();
    return (o);
}