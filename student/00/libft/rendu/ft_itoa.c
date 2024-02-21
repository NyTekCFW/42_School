/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:41:18 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/23 06:57:42 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc_lenght(long n)
{
	int	total_lenght;

	if (n < 0)
	{
		total_lenght = 2;
		n = n * (-1);
	}
	else
		total_lenght = 1;
	while ((n / 10) > 0)
	{
		n = n / 10;
		total_lenght++;
	}
	return (total_lenght);
}

static void	check(long *nbr, char *buffer)
{
	if (*nbr < 0)
	{
		*nbr = *nbr * (-1);
		buffer[0] = '-';
	}
}

char	*ft_itoa(int n)
{
	char	*buffer;
	int		lenght;
	int		i;
	long	nbr;

	nbr = n;
	lenght = alloc_lenght(nbr);
	buffer = ft_calloc(sizeof(char), lenght + 1);
	if (!buffer)
		return (NULL);
	check(&nbr, buffer);
	i = lenght;
	if (nbr == 0)
		buffer[i - 1] = '0';
	while (nbr > 0)
	{
		buffer[i - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	buffer[lenght] = 0;
	return (buffer);
}
