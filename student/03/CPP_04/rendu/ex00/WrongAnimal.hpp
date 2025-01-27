/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:36 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 09:14:19 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        //canon
        WrongAnimal(void);
        WrongAnimal(const std::string &type);
        WrongAnimal(const WrongAnimal &cpy);
        const WrongAnimal &operator=(const WrongAnimal &cpy);
        ~WrongAnimal(void);
        //MEMBER    
        const std::string &getType(void) const;
        void  makeSound() const;// pas de virtual qui va montrer le probleme du polymorphisme
};

std::ostream &operator<<(std::ostream &o, const WrongAnimal & c);
