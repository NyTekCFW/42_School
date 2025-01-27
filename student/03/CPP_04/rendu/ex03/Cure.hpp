/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:35:37 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 11:43:25 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure: public AMateria
{
    public:
        //canon
        Cure(void);
        Cure(const Cure& cpy);
        virtual ~Cure(void);
        const Cure& operator=(const Cure& cpy);
        //member
        virtual AMateria *clone(void) const;
        virtual void    use(ICharacter& target);
};
