/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:21 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 09:11:18 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
    public:
        //canon
        Cat(void);
        Cat(const std::string &type);
        Cat(const Cat& copy);
        virtual ~Cat(void);// destructeur virtuel pour garantir la destruction appropriée des objets dérivés
        Cat const &operator=(const Cat& cpy);
        //member
        virtual void makeSound() const;// méthode virtuelle pour le polymorphisme
};

std::ostream &operator<<(std::ostream &o, const Cat & c);