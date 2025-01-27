/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:53 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 09:19:47 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    int i = 0;

    std::cout << "Brain created with default constructor." << std::endl;
    for (i = 0; i < 100; i++)
    {
        this->_ideas[i] = "no idea found";
    }
}

Brain::Brain(const Brain& cpy)
{
	*this = cpy;
	std::cout << "Brain copy constructor called." << std::endl;
}
Brain& Brain::operator=(const Brain& cpy)
{
    int i = 0;

    if (this != &cpy)
    {
		for (i = 0; i < 100; i++)
        {
			this->_ideas[i] = cpy._ideas[i];
		}
	}
    std::cout << "Brain Assignement operator called." << std::endl;
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << "Brain Destructor Called." << std::endl;
}
