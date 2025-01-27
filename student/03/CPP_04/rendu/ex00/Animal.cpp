/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:11 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 08:56:07 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


//Canonique class
Animal::Animal(void): _type("Animal")
{
    std::cout << "Animal : Default Constructor called." << std::endl;
}

Animal::Animal(const std::string& type): _type(type)
{
    std::cout << "Animal Constructor : animal created." << std::endl;
}

Animal::Animal(const Animal& cpy)
{
    *this = cpy;
    std::cout << "Animal : " << this->_type << " copied." << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal : Destructor called." << std::endl;
}

const Animal& Animal::operator=(const Animal &cpy)
{
    this->_type = cpy.getType();
    std::cout << "Animal : Assignement operator for  : " << this->_type << "." << std::endl;
    return (*this);
}

std::string const &Animal::getType(void) const
{
    return (this->_type);
}

//generic sound
void Animal::makeSound() const
{
    std::cout << "Animal makes a generic sound!" << std::endl;
}

// output gettype
std::ostream &operator<<(std::ostream &o, const Animal & c)
{
    o << c.getType();
    return (o);
}
