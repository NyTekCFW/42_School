/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:14:08 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/19 22:49:19 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sl_scripts.h"

unsigned long	sl_hashstr(const char *str)
{
	unsigned long	hash;

	hash = 2784;
	while (*str++)
		hash = ((hash << 5) + hash) + (int)*str;
	return (hash);
}

size_t	sl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*sl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[sl_strlen(s)]);
	while (*s != (unsigned char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*sl_strjoin(char *s1, char *s2)
{
	char	*buffer;
	int		sz1;
	int		sz2;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	sz1 = sl_strlen(s1);
	sz2 = sl_strlen(s2);
	buffer = (char *)malloc((sz1 + sz2 + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	sl_memcpy(buffer, s1, sz1);
	sl_memcpy(&buffer[sz1], s2, sz2);
	buffer[sz1 + sz2] = '\0';
	free(s1);
	return (buffer);
}
