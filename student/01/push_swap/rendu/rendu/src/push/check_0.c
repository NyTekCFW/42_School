/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:18:47 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/16 06:03:37 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_digit(void)
{
	char	*j;
	size_t	i;
	size_t	x;
	size_t	e;

	j = get_piles(act_get)->joined;
	i = 0;
	e = 0;
	x = xstrlen(j);
	while (i < x)
	{
		if (!isdigit(j[i]) && j[i] != '-'
			&& j[i] != '+' && j[i] != ' ')
			return (print("Error"), 0);
		else if (isdigit(j[i]))
			e++;
		i++;
	}
	if (!(e > 0))
		return (print("Error"), 0);
	return (1);
}

static int	check_symbol(void)
{
	char	*j;
	size_t	i;
	size_t	x;

	j = get_piles(act_get)->joined;
	i = 0;
	x = xstrlen(j);
	while (i < x)
	{
		if (i != 0 && issymbol(j[i]) && j[i - 1] != ' ')
			return (print("Error"), 0);
		else if (j[i] == '+')
			j[i] = ' ';
		else if ((j[i] == '-' && !j[i + 1]))
			j[i] = ' ';
		else if (j[i] == '-' && !isdigit(j[i + 1]))
			return (print("Error"), 0);
		i++;
	}
	return (1);
}

int	check_dup2(char *str, __int64_t i)
{
	__int64_t	v[3];
	t_p			*ps;

	ps = get_piles(act_get);
	if (!ps->tab_entry
		&& (!xalloc((void **)&ps->tab_entry, ps->size, sizeof(__int64_t))))
		return (0);
	xmemcpy(v, (__int64_t []){0, 1, 0}, 3 * sizeof(__int64_t));
	ps->tab_entry[i] = xatoi(str);
	while (v[0] <= i)
	{
		v[2] = ps->tab_entry[v[0]];
		v[1] = 0;
		while (v[1] < i)
		{
			if (v[0] != v[1] && v[2] == ps->tab_entry[v[1]])
				return (0);
			v[1]++;
		}
		v[0]++;
	}
	return (1);
}

int	check_duplicate(void)
{
	size_t	i;
	char	*str;
	t_p		*piles;

	i = 0;
	str = NULL;
	piles = get_piles(act_get);
	while (i < piles->size)
	{
		str = piles->splitted[i];
		if (str)
		{
			if (xatoi(str) < -2147483648L)
				return (print("Error"), 0);
			else if (xatoi(str) > 2147483647L)
				return (print("Error"), 0);
			if (!check_dup2(str, i))
				return (print("Error"), 0);
		}
		else
			return (print("Error"), 0);
		i++;
	}
	return (1);
}

int	check_parsing(int argc, char **argv)
{
	t_p		*piles;
	int		i;
	size_t	a;

	i = 1;
	piles = get_piles(act_get);
	while (i < argc)
	{
		xstrjoin(&piles->joined, argv[i]);
		xstrjoin(&piles->joined, " ");
		i++;
	}
	if (check_digit() && check_symbol())
	{
		piles->splitted = xsplit(piles->joined, ' ', &piles->size);
		if (check_duplicate())
			insert_to_pile_a();
	}
	xfree((void **)&piles->joined);
	a = 0;
	while (a < piles->size)
		xfree((void **)&piles->splitted[a++]);
	xfree((void **)&piles->splitted);
	return (piles->p_size[pile_a] > 0);
}
