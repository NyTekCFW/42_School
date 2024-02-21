/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:14:41 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/14 05:51:10 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	mt_strlen(char *str)
{
	size_t	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

int	mt_print_str(char *str)
{
	write(1, str, mt_strlen(str));
	write(1, "\n", 1);
	return (mt_strlen(str) + 1);
}

void	mt_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
		mt_print_str("-2147483648");
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		mt_putnbr(nb / 10);
		mt_putnbr(nb % 10);
	}
	else
	{
		c = 0x30 + nb;
		write(1, &c, 1);
	}
}

int	mt_atoi(const char *str)
{
	int	res;
	int	neg;

	res = 0;
	neg = 0;
	if (str)
	{
		while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
			str++;
		if (*str == '-')
		{
			neg = -1;
			str++;
		}
		else if (*str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			res = res * 10 + (*str - '0');
			str++;
		}
	}
	if (neg < 0)
		return (-res);
	return (res);
}
