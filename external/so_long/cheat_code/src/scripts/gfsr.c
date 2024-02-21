/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfsr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:39:27 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/20 00:24:44 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sl_scripts.h"

void	Gfsr_God_f(t_gentity *player)
{
	if (player->flags & p_god)
		flag_clear(player, p_god);
	else
		flag_set(player, p_god);
	flag_print("Invulnerability: ", (player->flags & p_god));
}

void	Gfsr_Ufo_f(t_gentity *player)
{
	if (player->flags & p_ufo)
		flag_clear(player, p_ufo);
	else
		flag_set(player, p_ufo);
	flag_print("UFO Mode: ", (player->flags & p_ufo));
}

void	Gfsr_setviewpos_f(t_gentity *player)
{
	char	*var;

	var = NULL;
	(void)player;
	write(1, "Enter a X & Y origin\n", 21);
	var = gnl(0);
	var[sl_strlen(var) - 1] = 0;
	if (var)
	{
		free(var);
		return ;
	}
	write(1, "Error : wrong origin\n", 20);
}