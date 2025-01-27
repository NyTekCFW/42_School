/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:21 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 10:03:59 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    public:
        //canon
        Cat(void);
        Cat(const std::string &type);
        Cat(const Cat& copy);
        virtual ~Cat(void);
        Cat const &operator=(const Cat& cpy);
        //member
        virtual void makeSound() const;
        const std::string& getBrain(int index) const;
        void setBrain(int index, const std::string& idea);
        Brain *getBrainPtr(void);
    private:
        Brain *_brain;
};

std::ostream &operator<<(std::ostream &o, const Cat & c);