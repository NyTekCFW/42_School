/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:33 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 08:45:35 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//Canonique class
WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
    std::cout << "WrongAnimal : Default Constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type): _type(type)
{
    std::cout << "WrongAnimal : Constructor : " << this->_type << " WrongAnimal created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy)
{
    *this = cpy;
    std::cout << "WrongAnimal : " << this->_type << " copied." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal : Destructor called." << std::endl;
}

const WrongAnimal& WrongAnimal::operator=(const WrongAnimal &cpy)
{
    this->_type = cpy.getType();
    std::cout << "WrongAnimal : Assignement operator for  : " << this->_type << "." << std::endl;
    return (*this);
}

std::string const &WrongAnimal::getType(void) const
{
    return (this->_type);
}

//generic sound
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a wrong sound!" << std::endl;
}

// output gettype
std::ostream &operator<<(std::ostream &o, const WrongAnimal & c)
{
    o << c.getType();
    return (o);
}
