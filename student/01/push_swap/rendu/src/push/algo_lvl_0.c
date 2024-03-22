/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lvl_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 07:19:19 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/21 10:54:32 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_vec2	a_find_max(int c)
{
	t_p		*p;
	t_pile	*pile;
	int		i;
	int		t;

	p = get_piles(act_get);
	pile = p->pile[c];
	if (pile)
	{
		i = pile->val;
		t = pile->index;
		while (pile)
		{
			if (pile->val >= i)
			{
				i = pile->val;
				t = pile->index;
			}
			pile = pile->next;
		}
		return ((t_vec2){i, t});
	}
	return ((t_vec2){0, -1});
}

t_vec2	a_find_min(int c)
{
	t_p			*p;
	t_pile		*pile;
	__int64_t	i;
	__int64_t	t;

	p = get_piles(act_get);
	pile = p->pile[c];
	if (pile)
	{
		i = pile->val;
		t = pile->index;
		while (pile)
		{
			if (pile->val < i)
			{
				i = pile->val;
				t = pile->index;
			}
			pile = pile->next;
		}
		return ((t_vec2){i, t});
	}
	return ((t_vec2){0, -1});
}

t_vec2	a_find_next(__int64_t val, int c)
{
	t_p		*p;
	t_pile	*pile;
	t_vec2	m;
	t_vec2	f;

	p = get_piles(act_get);
	pile = p->pile[c];
	f = (t_vec2){0, -1};
	m = (t_vec2){val, val};
	while (pile)
	{
		if ((pile->val > val && m.y == val)
			|| (pile->val > val && pile->val < m.y))
		{
			m = (t_vec2){val, pile->val};
			f = (t_vec2){pile->val, pile->index};
		}
		pile = pile->next;
	}
	return (f);
}

t_vec2	a_find_prev(__int64_t val, int c)
{
	t_p		*p;
	t_pile	*pile;
	t_vec2	m;
	t_vec2	f;

	p = get_piles(act_get);
	pile = p->pile[c];
	f = (t_vec2){0, -1};
	m = (t_vec2){val, val};
	while (pile)
	{
		if ((pile->val < val && m.y == val)
			|| (pile->val < val && pile->val > m.y))
		{
			m = (t_vec2){val, pile->val};
			f = (t_vec2){pile->val, pile->index};
		}
		pile = pile->next;
	}
	return (f);
}

int	*assign_range(t_vec2 v[], __int64_t size)
{
	t_vec2		vg[2];
	__int64_t	i;

	if (xalloc((void **)&get_piles(act_get)->range_sizes, 5, sizeof(int *)))
	{
		vg[0] = (t_vec2){size / 5, size % 5};
		vg[1] = (t_vec2){0, 0};
		i = 0;
		while (i < 5)
		{
			vg[1].y = vg[1].x + vg[0].x - 1;
			if (i < vg[0].y)
				vg[1].y++;
			v[i] = (t_vec2){vg[1].x, vg[1].y};
			get_piles(act_get)->range_sizes[i] = vg[1].y - vg[1].x + 1;
			vg[1].x = vg[1].y + 1;
			i++;
		}
		return (get_piles(act_get)->range_sizes);
	}
	return (NULL);
}
