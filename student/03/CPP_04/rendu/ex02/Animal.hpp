/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:50 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 11:04:36 by lchiva           ###   ########.fr       */
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
    virtual void makeSound() const = 0;//methode virtuelle pour effectuer du polymorphisme et ainsi "redefinir" makesound
    std::string const &getType(void) const;
    protected:
        std::string _type;
};
/*
class Animal
{
    public:
    const Animal &operator=(const Animal &cpy);
    virtual ~Animal(void);
    virtual void makeSound(void) const = 0;
    std::string const &getType(void) const;
    void setType(const std::string& type);
    protected:
        std::string _type; 
        Animal(void);
        Animal(const std::string& type);
        Animal(const Animal& cpy);
};
*/
std::ostream &operator<<(std::ostream &o, const Animal & c);