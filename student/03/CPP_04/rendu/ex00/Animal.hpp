/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:15 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 09:10:56 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
    public:
    //canon
    Animal(void);
    Animal(const std::string& type);
    Animal(const Animal& cpy);
    const Animal &operator=(const Animal &cpy);
    virtual ~Animal(void);//destructeur virtuelle pour faire correctement la destruction des objet derive
    //member
    virtual void makeSound() const;//methode virtuelle pour effectuer du polymorphisme et ainsi "redefinir" makesound
    std::string const &getType(void) const;
    protected:
        std::string _type; 
};

std::ostream &operator<<(std::ostream &o, const Animal & c);