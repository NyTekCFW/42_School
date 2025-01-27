/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:35:42 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 11:43:59 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice: public AMateria
{
    public:
        //canon
        Ice(void);
        Ice(const Ice& cpy);
        virtual ~Ice(void);
        const Ice& operator=(const Ice& cpy);
        //member
        virtual AMateria *clone(void) const;
        virtual void    use(ICharacter& target);
};
