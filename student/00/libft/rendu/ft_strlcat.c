/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 06:05:34 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/09 22:32:22 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	k;
	size_t	i;
	size_t	rd;
	size_t	rs;

	i = ft_strlen(dst);
	k = 0;
	rd = i;
	rs = ft_strlen(src);
	if (size < 1)
		return (rs + size);
	while (src[k] && i < size - 1)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	if (size < rd)
		return (rs + size);
	else
		return (rd + rs);
}
