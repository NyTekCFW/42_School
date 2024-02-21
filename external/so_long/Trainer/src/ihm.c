/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ihm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:50:36 by lchiva            #+#    #+#             */
/*   Updated: 2024/02/13 16:15:28 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dbg.h"

void	instawin(t_rev *rev)
{
	long	val;

	rev->var.god = !rev->var.god;
	val = rev->cheat[p_collect].off_value;
	if (rev->var.god)
		val = rev->cheat[p_collect].on_value;
	write_memory(rev, rev->cheat[p_collect].offset, val);
	if (rev->var.god)
		printw("Insta Win : ON\n");
	else
		printw("Insta Win : OFF\n");
}

void	invulnerability(t_rev *rev)
{
	long	val;

	rev->var.god = !rev->var.god;
	val = rev->cheat[p_god].off_value;
	if (rev->var.god)
		val = rev->cheat[p_god].on_value;
	write_memory(rev, rev->cheat[p_god].offset, val);
	if (rev->var.god)
		printw("God Mode : ON\n");
	else
		printw("God Mode : OFF\n");
}

int	init_ihm(t_rev *rev)
{
	int	ch;

	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	printw("1 = God Mod\n2 = Instant Win\nESC For Exit\n");
	refresh();
	while (1)
	{
		ch = getch();
		if (ch == '1')
			invulnerability(rev);
		else if (ch == '2')
			instawin(rev);
		else if (ch == 27)
			break ;
	}
	endwin();
	return (1);
}
