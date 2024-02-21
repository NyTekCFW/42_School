/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:54:11 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/19 23:04:52 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 0x09 && c <= 0x0D) || (c == 0x20))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	mp;

	mp = 1;
	res = 0;
	i = 0;
	while (nptr[i] && ft_isspace(nptr[i]) == 1)
		i++;
	if ((nptr[i] && nptr[i] == '+') || (nptr[i] && nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			mp *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= 0x30 && nptr[i] <= 0x39)
		res = (res * 10) + (nptr[i++] - 0x30);
	return (res * mp);
}
