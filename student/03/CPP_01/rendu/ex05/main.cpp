/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:40:13 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:40:13 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl    guy;

    guy.complain("DEBUG");
    guy.complain("INFO");
    guy.complain("WARNING");
    guy.complain("ERROR");
    return (1);
}