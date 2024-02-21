/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scripts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:55:54 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/20 00:20:14 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sl_scripts.h"

void	init_scripts(t_gf *sc_l)
{
	t_gf	*i;

	i = sc_l;
	i = add_scripts(i, Gfsr_God_f, "god");
	i = add_scripts(i, Gfsr_Ufo_f, "ufo");
}

t_gf	*add_scripts(t_gf *sc_l, void (*(func))(), char	*name)
{
	t_gf	*newl;
	
	if (sc_l == NULL)
		return (NULL);
	newl = (t_gf *)malloc(sizeof(t_gf) + 1);
	if (!newl)
		return (NULL);
	newl->func = func;
	newl->name = sl_hashstr(name);
	newl->next = NULL;
	sc_l->next = newl;
	return (sc_l->next);
}

t_gf	*Cmd_f(t_gf *sc_l, char *argv)
{
	while (sc_l && sc_l->name != sl_hashstr(argv))
		sc_l = sc_l->next;
	if (!sc_l)
		return (void *)0;
	return (sc_l);
}

void	execute_scripts(t_gentity *ent, t_gf *sc_l, char *argv)
{
	t_gf	*sc;

	argv[sl_strlen(argv) - 1] = 0;
	sc = Cmd_f(sc_l, argv);
	if (sc)
		sc->func(ent);
	else
		write(1, "Command not found\n", 18);
}