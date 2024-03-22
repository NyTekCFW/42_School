/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:17:24 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/16 07:03:54 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	move_up(int pl)
{
	t_pile	*px;
	t_p		*p;

	p = get_piles(act_get);
	if (xalloc((void **)&px, 1, sizeof(t_pile)))
	{
		xmemcpy(px, p->pile[pl], sizeof(t_pile));
		free(p->pile[pl]);
		p->pile[pl] = px->next;
		px->next = NULL;
		get_last_pile(pl)->next = px;
		re_attribute_index(pl);
	}
}

void	ra(void)
{
	t_p	*p;

	p = get_piles(act_get);
	if (p->p_size[pile_a] > 1)
	{
		move_up(pile_a);
		print("ra");
	}
}

void	rb(void)
{
	t_p	*p;

	p = get_piles(act_get);
	if (p->p_size[pile_b] > 1)
	{
		move_up(pile_b);
		print("rb");
	}
}

void	rr(void)
{
	t_p	*p;

	p = get_piles(act_get);
	if (p->p_size[pile_a] > 1 && p->p_size[pile_b] > 1)
	{
		move_up(pile_a);
		move_up(pile_b);
		print("rr");
	}
}
