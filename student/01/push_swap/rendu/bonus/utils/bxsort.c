/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bxsort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:07:38 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/22 19:07:49 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_ps.h"

static int	cmp_tab(__int64_t tab[], __int64_t tab1[], __int64_t size)
{
	__int64_t	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == tab1[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	xsort(__int64_t tab[], __int64_t size)
{
	__int64_t	c[4];

	xmemcpy(c, (__int64_t []){0, 1, 0, 0}, 4 * sizeof(__int64_t));
	while (c[0] < size)
	{
		c[2] = tab[c[0]];
		c[1] = c[0] + 1;
		while (c[1] < size)
		{
			if (tab[c[1]] < c[2])
			{
				c[2] = tab[c[1]];
				c[3] = tab[c[0]];
				tab[c[0]] = tab[c[1]];
				tab[c[1]] = c[3];
			}
			c[1]++;
		}
		c[0]++;
	}
	return (1);
}

int	is_sorted(int x)
{
	__int64_t	*v[2];
	t_p			*p;
	t_pile		*pile;
	int			i;
	int			c;

	p = get_piles(act_get);
	i = 0;
	if (xalloc((void **)&v[0], p->p_size[x], p->p_size[x] * sizeof(__int64_t))
		&& xalloc((void **)&v[1], p->p_size[x],
			p->p_size[x] * sizeof(__int64_t)))
	{
		pile = p->pile[x];
		while (pile)
		{
			v[0][i] = pile->val;
			v[1][i] = pile->val;
			pile = pile->next;
			i++;
		}
		xsort(v[0], p->p_size[x]);
		c = cmp_tab(v[1], v[0], p->p_size[x]);
		return (xfree((void **)&v[1]), xfree((void **)&v[0]), c);
	}
	return (0);
}

void	sort_type(void)
{
	char	*line;
	t_p		*p;

	p = get_piles(act_get);
	init_cmds(p);
	while (1)
	{
		line = gnl(0);
		if (!find_and_execute(p, line))
		{
			xfree((void **)&line);
			break ;
		}
		xfree((void **)&line);
	}
}
