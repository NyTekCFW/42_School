/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:42 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 09:14:51 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        //CANON
        WrongCat(void);
        WrongCat(const std::string &type);
        WrongCat(const WrongCat &cpy);
        const WrongCat &operator=(const WrongCat &cpy);
        ~WrongCat();
        //member
        void  makeSound() const;
};

std::ostream &operator<<(std::ostream &o, const WrongCat & c);
