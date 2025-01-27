/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:35:15 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 12:35:05 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    int i = 0;
    for (i = 0; i < 4; ++i)
    {
        this->_learnslots[i] = NULL;
    }
    /**///std::cout << "MateriaSource::MateriaSource - Default constructor called. MateriaSource instance initialized." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& cpy): IMateriaSource(cpy), _learnslots()
{
    int i = 0;

    for (i = 0; i < 4; ++i)
    {
        if (cpy._learnslots[i])
            this->_learnslots[i] = cpy._learnslots[i]->clone();
        else
            this->_learnslots[i] = NULL;
    }
    /**///std::cout << "MateriaSource::MateriaSource - Copy constructor called. A new MateriaSource was created from a copy." << std::endl;
}

const MateriaSource& MateriaSource::operator=(const MateriaSource& cpy)
{
    int i = 0;
    if (this != &cpy)
    {
        for (i = 0; i < 4; i++)
        {
            if (this->_learnslots[i])
            {
                delete(this->_learnslots[i]);
                this->_learnslots[i] = NULL;
            }
            if (cpy._learnslots[i])
                this->_learnslots[i] = cpy._learnslots[i]->clone();
        }
    }
    /**///std::cout << "MateriaSource::operator= - Assignment operator called. MateriaSource copied from another instance." << std::endl;
    return (*this);
}

MateriaSource::~MateriaSource(void)
{
    int i = 0;

    for (i = 0; i < 4; ++i)
    {
        if (this->_learnslots[i])
        {
            delete(this->_learnslots[i]);
            this->_learnslots[i] = NULL;
        }
    }
    /**///std::cout << "MateriaSource::~MateriaSource - Destructor called. MateriaSource instance is being destroyed." << std::endl;
}

void MateriaSource::learnMateria(AMateria*m)
{
    int i = 0;
    
    for (i = 0; i < 4; ++i)
    {
        if (!this->_learnslots[i] && m && (m->getType() == "cure" || m->getType() == "ice"))
        {
            this->_learnslots[i] = m->clone();
            delete(m);
            /**///std::cout << "MateriaSource::learnMateria() - " << this->_learnslots[i]->getType() << " learned at index " << i << std::endl;
            return ;
        }
    }
    if (m)
        delete(m);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;
    
    if (type == "")
        return (NULL);
    for (i = 0; i < 4; i++)
    {
        if (this->_learnslots[i] && this->_learnslots[i]->getType() == type)
            return (this->_learnslots[i]->clone());
    }
    std::cout << "MateriaSource::createMateria() - Invalid type parameter [" << type << "] provided." << std::endl;
    return (NULL);
}


