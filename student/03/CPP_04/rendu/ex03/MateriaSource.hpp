/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:36:00 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 11:44:40 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        AMateria *_learnslots[4];
    public:
    //canon
    MateriaSource(void);
    MateriaSource(const MateriaSource& cpy);
    virtual ~MateriaSource(void);
    const MateriaSource& operator=(const MateriaSource& cpy);
    //member
    void learnMateria(AMateria*m);
    AMateria* createMateria(std::string const & type);
};