/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lvl_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:39:28 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/21 04:45:57 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(void)
{
	t_vec2	vn;

	vn = a_find_min(pile_a);
	if (!is_sorted(pile_a))
	{
		if (vn.y == 0)
			return (ra(), sa(), rra(), (void)0);
		else if (vn.y == 1 && a_find_next(vn.x, pile_a).y == 0)
			return (sa(), (void)0);
		else if (vn.y == 1 && a_find_next(vn.x, pile_a).y == 2)
			return (ra(), (void)0);
		else if (vn.y == 2 && a_find_next(vn.x, pile_a).y == 0)
			return (rra(), (void)0);
		else if (vn.y == 2 && a_find_next(vn.x, pile_a).y == 1)
			return (sa(), rra(), (void)0);
	}
}

void	sort_four(void)
{
	t_p		*p;
	t_vec2	vn;

	p = get_piles(act_get);
	pb();
	sort_three();
	vn = a_find_next(p->pile[pile_b]->val, pile_a);
	if (vn.y == -1)
		return (pa(), ra(), (void)0);
	if (vn.y == 0)
		return (pa(), (void)0);
	if (vn.y == 1)
		return (pa(), sa(), (void)0);
	if (vn.y == 2)
		return (pa(), rra(), sa(), ra(), ra(), (void)0);
}

void	sort_five(void)
{
	t_p		*p;
	int		r;

	p = get_piles(act_get);
	while (p->p_size[pile_a] > 3 && !is_sorted(pile_a))
	{
		if (a_find_min(pile_a).y == 0)
		{
			pb();
			continue ;
		}
		r = ra_is_better(p);
		if (r)
			ra();
		else
			rra();
	}
	if (!is_sorted(pile_a))
		sort_three();
	while (p->p_size[pile_b] > 0)
		pa();
}
