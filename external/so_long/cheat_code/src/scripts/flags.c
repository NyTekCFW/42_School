/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:11:05 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/20 00:19:18 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sl_scripts.h"

void	flag_set(t_gentity *ent, unsigned int flag)
{
	ent->flags |= flag;
}

void	flag_clear(t_gentity *ent, unsigned int flag)
{
	ent->flags &= ~flag;
}

void	flag_print(char	*str, unsigned int status)
{
	write(1, "\033[1m", 4);
	write(1, str, sl_strlen(str));
	if (status)
		write(1, "\033[32mON", 7);
	else
		write(1, "\033[31mOFF", 8);
	write(1, "\033[0m\n", 5);
}
