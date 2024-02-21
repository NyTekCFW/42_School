/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:41:12 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/14 02:10:14 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*mt_memset(void *s, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	ux;

	dest = s;
	ux = (unsigned char)c;
	while (n--)
		*dest++ = ux;
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*mt_strjoin(char *s1, char s2)
{
	char	*buffer;
	int		sz1;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1)
		return (NULL);
	sz1 = mt_strlen(s1);
	buffer = (char *)malloc((sz1 + 2) * sizeof(char));
	if (!buffer)
		return (free(s1), NULL);
	ft_memcpy(buffer, s1, sz1);
	buffer[sz1] = s2;
	buffer[sz1 + 1] = '\0';
	return (free(s1), s1 = NULL, buffer);
}
