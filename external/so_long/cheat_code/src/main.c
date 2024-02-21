/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:02:09 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/20 00:09:45 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sl_scripts.h"

int	main(int argc, char **argv)
{
	t_gentity	ent;
	t_gf		sc_l;
	char		*line;

        (void)argc;
        (void)argv;
	sc_l.func = Gfsr_setviewpos_f;
	sc_l.name = sl_hashstr("setviewpos");
	sc_l.next = NULL;
	init_scripts(&sc_l);
	ent.etype = 'P';
	ent.flags = 0;
	ent.health = 100;
	
	line = NULL;	
	while (1)
	{
		line = gnl(0);
		if (line)
		{
			printf("cmd : %s\n", line);
			execute_scripts(&ent, &sc_l, line);
			free(line);
			line = NULL;
		}
	}
}


//cc main.c utils/gnl.c utils/memory.c utils/strings.c scripts/flags.c scripts/gfsr.c scripts/scripts.c
