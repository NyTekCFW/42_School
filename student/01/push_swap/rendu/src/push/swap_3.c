/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:38:04 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/16 07:04:26 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	move_down(int pl)
{
	t_pile	*prev;
	t_pile	*last;
	t_pile	*px;
	t_p		*p;

	p = get_piles(act_get);
	if (xalloc((void **)&px, 1, sizeof(t_pile)))
	{
		last = get_last_pile(pl);
		if (last)
		{
			prev = find_prev_pile(pl, last);
			xmemcpy(px, last, sizeof(t_pile));
			xfree((void **)&last);
			prev->next = NULL;
			px->next = p->pile[pl];
			p->pile[pl] = px;
			re_attribute_index(pl);
		}
	}
}

void	rra(void)
{
	t_p	*p;

	p = get_piles(act_get);
	if (p->p_size[pile_a] > 1)
	{
		move_down(pile_a);
		print("rra");
	}
}

void	rrb(void)
{
	t_p	*p;

	p = get_piles(act_get);
	if (p->p_size[pile_b] > 1)
	{
		move_down(pile_b);
		print("rrb");
	}
}

void	rrr(void)
{
	t_p	*p;

	p = get_piles(act_get);
	if (p->p_size[pile_a] > 1 && p->p_size[pile_b] > 1)
	{
		move_down(pile_a);
		move_down(pile_b);
		print("rrr");
	}
}
