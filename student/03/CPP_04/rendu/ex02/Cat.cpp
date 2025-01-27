/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:17 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 10:04:03 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//canon
Cat::Cat(void): Animal("Cat")
{
    try
    {
        this->_brain = new Brain();
        std::cout << "Cat default constructor called" << std::endl;
    }
    catch(const std::bad_alloc& cat_alloc)
    {
        std::cerr << "Bad allocated memory for Cat's Brain: " << cat_alloc.what() << std::endl;
        this->_brain = NULL;
    }
}

Cat::Cat(const std::string &type): Animal(type), _brain()
{
    try
    {
        this->_brain = new Brain();
        std::cout << "Cat from Animal constructor called" << std::endl;
    }
    catch(const std::bad_alloc& cat_alloc)
    {
        std::cerr << "Bad allocated memory for Cat's Brain: " << cat_alloc.what() << std::endl;
        this->_brain = NULL;
    }
}

Cat::Cat(const Cat& cpy): Animal(cpy), _brain(new Brain(*cpy._brain))
{
    std::cout << "Cat from Animal: " << Animal::_type << " copied." << std::endl;
}

const Cat &Cat::operator=(const Cat& cpy)
{
    if (this != &cpy)
    {
        Animal::operator=(cpy);
        delete(this->_brain);
        this->_brain = new Brain(*cpy._brain);
    }
   std::cout << "Assignment operator for Cat from Animal " << Animal::_type << " called." << std::endl;
   return (*this);
}

Cat::~Cat(void)
{
    if (this->_brain)
        delete this->_brain;
    std::cout << "Cat from Animal " << Animal::_type << " Destructor Called." << std::endl;
}
//member

void Cat::makeSound() const
{
    std::cout << "Cat From Animal " << Animal::_type << " : Meow!" << std::endl;
}

const std::string& Cat::getBrain(int index) const
{
    if (index >= 0 && index < 100)
        return (this->_brain[index]._ideas[index]);
    return (this->_brain[0]._ideas[0]);
}

void Cat::setBrain(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        this->_brain[index]._ideas[index] = idea;
}

Brain *Cat::getBrainPtr(void)
{
    return this->_brain;
}

std::ostream &operator<<(std::ostream &o, const Cat & c)
{
    o << c.getType();
    return (o);
}