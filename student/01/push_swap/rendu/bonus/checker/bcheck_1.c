/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcheck_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 05:38:16 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/22 17:13:47 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_ps.h"

static void	assert_data_a(t_pile *pile, int e)
{
	size_t	i;
	t_p		*piles;

	i = 0;
	piles = get_piles(act_get);
	pile->index = e;
	pile->val = piles->tab_entry[e];
	while (i < piles->size)
	{
		if (piles->sorted_entry[i] == pile->val)
		{
			pile->f_index = i;
			break ;
		}
		i++;
	}
	pile->next = NULL;
}

static void	init_f_index(t_p *p)
{
	if (xalloc((void **)&p->sorted_entry, p->size, sizeof(__int64_t)))
	{
		xmemcpy(p->sorted_entry, p->tab_entry, p->size * sizeof(__int64_t));
		xsort(p->sorted_entry, p->size);
	}
}

void	insert_to_pile_a(void)
{
	size_t	i;
	t_p		*piles;
	t_pile	*pile;

	i = 1;
	piles = get_piles(act_get);
	init_f_index(piles);
	if (xalloc((void **)&piles->pile[pile_a], 1, sizeof(t_pile)))
	{
		assert_data_a(piles->pile[pile_a], 0);
		pile = piles->pile[pile_a];
		piles->p_size[pile_a]++;
		while (i < piles->size)
		{
			xalloc((void **)&pile->next, 1, sizeof(t_pile));
			assert_data_a(pile->next, (int)i);
			piles->p_size[pile_a]++;
			pile = pile->next;
			i++;
		}
	}
	xfree((void **)&piles->sorted_entry);
}
