/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:46:57 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/08 09:20:14 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
    public:
    //Canon
    Brain(void);
    Brain(const Brain& cpy);
    Brain& operator=(const Brain& cpy);
    ~Brain(void);
    //Member
    std::string _ideas[100];
};