/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:35:22 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 11:31:15 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    public:
        //canon
        AMateria(std::string const & type);
        AMateria(const AMateria& cpy);
        const AMateria& operator=(const AMateria& cpy);
        virtual ~AMateria(void);
        //member
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        std::string const & getType() const;
    protected:
        std::string _type;
};
