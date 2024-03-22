/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bswap_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:17:20 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/22 19:24:35 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_ps.h"

static void	move_pile(int src, int dest)
{
	t_p		*p;
	t_pile	*tmp[2];

	p = get_piles(act_get);
	if (xalloc((void **)&tmp[0], 1, sizeof(t_pile)))
	{
		xmemcpy(tmp[0], p->pile[src], sizeof(t_pile));
		if (p->pile[dest])
			tmp[0]->next = p->pile[dest];
		else
			tmp[0]->next = NULL;
		p->pile[dest] = tmp[0];
		if (p->pile[src]->next)
		{
			tmp[1] = p->pile[src]->next;
			xfree((void **)&p->pile[src]);
			p->pile[src] = tmp[1];
		}
		else
		{
			xfree((void **)&p->pile[src]);
			p->pile[src] = NULL;
		}
		return (re_attribute_index(dest), re_attribute_index(src), (void)0);
	}
}

void	pa(void)
{
	t_p	*p;

	p = get_piles(act_get);
	if (p->p_size[pile_b] >= 1)
	{
		move_pile(pile_b, pile_a);
	}
}

void	pb(void)
{
	t_p	*p;

	p = get_piles(act_get);
	if (p->p_size[pile_a] >= 1)
	{
		move_pile(pile_a, pile_b);
	}
}
