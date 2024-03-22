/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:11:17 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/16 01:11:18 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	xcountword(char *s, char c, size_t *sz)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	*sz = count;
	return (count);
}

static int	xword_len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**xpurge_split(char **tab, int index)
{
	while (index >= 0)
		free(tab[index--]);
	free(tab);
	return (NULL);
}

char	**xsplit(char *s, char c, size_t *ts)
{
	int		i;
	int		o;
	char	**buffer;

	i = 0;
	o = 0;
	if (xalloc((void **)&buffer, xcountword(s, c, ts) + 1, sizeof(char *)))
	{
		while (*s)
		{
			if (*s != c)
			{
				o = xword_len(s, c);
				buffer[i] = xsubstr(s, 0, o);
				if (!buffer[i])
					return (xpurge_split(buffer, i));
				i++;
				s += o;
			}
			else
				s++;
		}
		return (buffer);
	}
	return (NULL);
}

void	xputnbr(__int64_t n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		xputnbr(n / 10);
		xputnbr(n % 10);
	}
	else
		write(1, (char []){0x30 + n}, 1);
}
