/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:30:25 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/10 01:26:15 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c;
	const unsigned char	*d;

	c = (const unsigned char *)s1;
	d = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*c != *d)
			return ((int)(*c - *d));
		c++;
		d++;
	}
	return (0);
}
