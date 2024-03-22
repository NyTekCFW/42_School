/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lvl_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:05:13 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/21 12:44:47 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ra_next_is_better(t_vec2 r, int mid)
{
	t_vec2	rr;

	rr = a_find_next(r.x, pile_a);
	if (rr.y > mid)
		return (0);
	else if (rr.y < mid)
		return (1);
	return (0);
}

int	ra_is_better(t_p *p)
{
	t_vec2	r;
	int		mid;

	mid = p->p_size[pile_a] / 2;
	r = a_find_min(pile_a);
	if (r.y > mid)
		return (0);
	else if (r.y < mid)
		return (1);
	else if (r.y == mid)
		return (ra_next_is_better(r, mid));
	return (0);
}

int	is_in_range(t_vec2 v, int index)
{
	if (index >= v.x && index <= v.y)
		return (1);
	return (0);
}

void	rotate_b_pile(t_p *p, t_vec2 v)
{
	__int64_t	n;

	n = v.x + ((v.y - v.x) / 2) + 1;
	if (p->pile[pile_b]->val <= n)
		rb();
}

void	main_algo(void)
{
	t_p		*p;
	t_vec2	rng[5];
	t_vec2	rx;

	p = get_piles(act_get);
	xmemset(rng, 0, sizeof(rng));
	assign_range(rng, p->size);
	rx = (t_vec2){0, p->range_sizes[0]};
	main_assign(p, rng, rx);
	sort_three();
	final_push(p);
}
