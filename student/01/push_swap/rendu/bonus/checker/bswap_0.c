/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bswap_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:57:26 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/22 19:24:28 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_ps.h"

static void	swap_data(t_pile *src, t_pile *dest)
{
	__int64_t	v[2];

	v[0] = src->val;
	v[1] = src->f_index;
	src->val = dest->val;
	src->f_index = dest->f_index;
	dest->val = v[0];
	dest->f_index = v[1];
}

void	sa(void)
{
	t_p	*piles;

	piles = get_piles(act_get);
	if (piles->p_size[pile_a] > 1)
	{
		swap_data(piles->pile[pile_a], piles->pile[pile_a]->next);
	}
}

void	sb(void)
{
	t_p	*piles;

	piles = get_piles(act_get);
	if (piles->p_size[pile_b] > 1)
	{
		swap_data(piles->pile[pile_b], piles->pile[pile_b]->next);
	}
}

void	ss(void)
{
	t_p		*piles;

	piles = get_piles(act_get);
	if (piles->p_size[pile_a] > 1 && piles->p_size[pile_b] > 1)
	{
		swap_data(piles->pile[pile_a], piles->pile[pile_a]->next);
		swap_data(piles->pile[pile_b], piles->pile[pile_b]->next);
	}
}
