/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:24 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 10:03:52 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
    try
    {
        this->_brain = new Brain();
        std::cout << "Dog default constructor called" << std::endl;
    }
    catch(const std::bad_alloc& Dog_alloc)
    {
        std::cerr << "Bad alloDoged memory for Dog's Brain: " << Dog_alloc.what() << std::endl;
        this->_brain = NULL;
    }
}

Dog::Dog(const std::string &type): Animal(type), _brain()
{
    try
    {
        this->_brain = new Brain();
        std::cout << "Dog from Animal constructor called" << std::endl;
    }
    catch(const std::bad_alloc& Dog_alloc)
    {
        std::cerr << "Bad alloDoged memory for Dog's Brain: " << Dog_alloc.what() << std::endl;
        this->_brain = NULL;
    }
}

Dog::Dog(const Dog& cpy): Animal(cpy), _brain(new Brain(*cpy._brain))
{
    std::cout << "Dog from Animal: " << Animal::_type << " copied." << std::endl;
}

const Dog &Dog::operator=(const Dog& cpy)
{
    if (this != &cpy)
    {
        Animal::operator=(cpy);
        delete(this->_brain);
        this->_brain = new Brain(*cpy._brain);
    }
   std::cout << "Assignment operator for Dog from Animal " << Animal::_type << " called." << std::endl;
   return (*this);
}

Dog::~Dog(void)
{
    if (this->_brain)
        delete this->_brain;
    std::cout << "Dog from Animal " << Animal::_type << " Destructor Called." << std::endl;
}
//member

void Dog::makeSound() const
{
    std::cout << "Dog From Animal " << Animal::_type << " : bark!" << std::endl;
}

const std::string& Dog::getBrain(int index) const
{
    if (index >= 0 && index < 100)
        return (this->_brain[index]._ideas[index]);
    return (this->_brain[0]._ideas[0]);
}

void Dog::setBrain(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        this->_brain[index]._ideas[index] = idea;
}

Brain *Dog::getBrainPtr(void)
{
    return this->_brain;
}

std::ostream &operator<<(std::ostream &o, const Dog & c)
{
    o << c.getType();
    return (o);
}
