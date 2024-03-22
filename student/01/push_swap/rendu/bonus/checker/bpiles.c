/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bpiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:03:24 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/22 17:13:44 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_ps.h"

t_p	*get_piles(int act)
{
	static t_p	*piles;

	if (act == act_get && piles)
		return (piles);
	else if (act == act_init && xalloc((void **)&piles, 1, sizeof(t_p)))
		return (piles);
	else if (act == act_free)
		return (free(piles), piles = NULL, NULL);
	return (NULL);
}

void	print_pile(int p)
{
	size_t	i;
	t_p		*piles;
	t_pile	*pile;

	i = 0;
	piles = get_piles(act_get);
	pile = piles->pile[p];
	while (i < piles->size)
	{
		if (pile)
		{
			xputnbr(pile->val);
			xputnbr(pile->f_index);
			print("");
		}
		else
			break ;
		pile = pile->next;
		i++;
	}
}

void	re_attribute_index(int p)
{
	size_t	i;
	t_p		*piles;
	t_pile	*pile;

	i = 0;
	piles = get_piles(act_get);
	pile = piles->pile[p];
	if (pile)
	{
		while (pile)
		{
			pile->index = i;
			pile = pile->next;
			i++;
		}
		piles->p_size[p] = i;
	}
	else
		piles->p_size[p] = 0;
}

t_pile	*get_last_pile(int a)
{
	t_pile	*p;

	p = get_piles(act_get)->pile[a];
	if (!p)
		return (NULL);
	while (p->next)
	{
		if (p->next)
			p = p->next;
	}
	return (p);
}

t_pile	*find_prev_pile(int a, t_pile *ptr)
{
	t_pile	*p;

	p = get_piles(act_get)->pile[a];
	if (!p)
		return (NULL);
	while (p->next && p->next != ptr)
	{
		if (p->next)
			p = p->next;
	}
	return (p);
}
