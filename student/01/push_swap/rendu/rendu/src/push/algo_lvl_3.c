/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lvl_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:05:45 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/22 13:59:11 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	main_assign(t_p *p, t_vec2 rng[], t_vec2 rx)
{
	int	x;

	x = 0;
	while (p->p_size[pile_a] > 3)
	{
		if (is_in_range(rng[rx.x], p->pile[pile_a]->f_index)
			&& p->pile[pile_a]->f_index < (p->size - 3))
		{
			pb();
			if (p->p_size[pile_b] > 1)
				rotate_b_pile(p, rng[rx.x]);
			x++;
			if (x >= rx.y && rx.x < 5)
			{
				rx = (t_vec2){rx.x + 1, p->range_sizes[rx.x + 1]};
				x = 0;
			}
		}
		else
			ra();
	}
}

void	push_value(t_p *p, size_t **i)
{
	pa();
	if (p->pile[pile_a]->next->f_index == p->pile[pile_a]->f_index - 1)
		sa();
	**i -= 1;
}

int	is_for_sa(t_p *p)
{
	if (p->pile[pile_a]->f_index != p->pile[pile_a]->next->f_index - 1
		&& p->pile[pile_a]->f_index != p->pile[pile_a]->next->f_index - 2)
		return (0);
	return (1);
}

void	find_best(t_p *p, size_t *i)
{
	int			med;
	t_vec2		max;

	max = a_find_max(pile_b);
	med = p->p_size[pile_b] / 2;
	while (get_last_pile(pile_a)->f_index + 1 == p->pile[pile_a]->f_index
		&& p->pile[pile_a]->f_index + 1 == p->pile[pile_a]->next->f_index)
	{
		rra();
		*i -= 1;
	}
	if ((get_last_pile(pile_a)->f_index == p->size - 1
			&& p->pile[pile_b]->f_index < *i - 1)
		|| (p->pile[pile_b]->f_index > get_last_pile(pile_a)->f_index
			&& p->pile[pile_b]->f_index < *i - 1))
		return (pa(), ra(), (void)0);
	if (max.y == 0)
		return (push_value(p, &i), (void)0);
	else if (max.y >= med)
		return (rrb(), (void)0);
	else if (max.y < med)
		return (rb(), (void)0);
}

void	final_push(t_p *p)
{
	size_t	index;

	index = p->size - 4;
	pa();
	if (!is_for_sa(p))
		ra();
	while (p->p_size[pile_b] > 0)
		find_best(p, &index);
	while (p->pile[pile_a]->f_index != 0)
		rra();
}
