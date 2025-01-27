/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:27 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 09:11:26 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
    public:
        //canon
        Dog(void);
        Dog(const std::string &type);
        Dog(const Dog& copy);
        virtual ~Dog(void);// destructeur virtuel pour garantir la destruction appropriée des objets dérivés
        Dog const &operator=(const Dog& cpy);
        //member
        virtual void makeSound() const;// méthode virtuelle pour le polymorphisme
};

std::ostream &operator<<(std::ostream &o, const Dog & c);