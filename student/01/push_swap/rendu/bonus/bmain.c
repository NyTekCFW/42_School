/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:52:24 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/22 23:34:42 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bonus_ps.h"

void	free_pile(int c)
{
	t_pile	*p[2];

	p[0] = get_last_pile(c);
	while (p[0] && p[0] != get_piles(act_get)->pile[c])
	{
		xmemset(p[0], 0, sizeof(t_pile));
		if (p[0])
		{
			p[1] = find_prev_pile(c, p[0]);
			xfree((void **)&p[0]);
			if (p[1])
				p[1]->next = NULL;
		}
		p[0] = get_last_pile(c);
	}
	xfree((void **)&get_piles(act_get)->pile[c]);
}

void	free_push(t_p *piles)
{
	xfree((void **)&piles->tab_entry);
	if (piles->pile[pile_a])
		free_pile(pile_a);
	if (piles->pile[pile_b])
		free_pile(pile_b);
	if (piles->range_sizes)
		xfree((void **)&piles->range_sizes);
	get_piles(act_free);
}

int	main(int argc, char **argv)
{
	t_p		*piles;

	if (argc <= 1)
		return (0);
	piles = get_piles(act_init);
	if (check_parsing(argc, argv))
	{
		sort_type();
		if (is_sorted(pile_a) && piles->p_size[pile_b] == 0)
			print("OK");
		else
			print("KO");
	}
	else if (piles->p_size[pile_a] > 0 && piles->p_size[pile_b] == 0
		&& is_sorted(pile_a))
		print("OK");
	free_push(piles);
	return (1);
}
