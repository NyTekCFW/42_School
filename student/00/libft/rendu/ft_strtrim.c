/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:21:56 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/16 20:10:37 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_presence(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buffer;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_presence(set, s1[start]))
		start++;
	while (end > start && ft_presence(set, s1[end - 1]))
		end--;
	buffer = (char *)ft_calloc(sizeof(char), (end - start) + 1);
	if (!buffer)
		return (NULL);
	while (start < end)
		buffer[i++] = s1[start++];
	return (buffer);
}
