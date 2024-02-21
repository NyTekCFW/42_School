/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 06:42:42 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/16 20:04:41 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
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
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_purge_split(char **tab, int index)
{
	while (index >= 0)
		free(tab[index--]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		o;
	char	**buffer;

	i = 0;
	o = 0;
	buffer = (char **)ft_calloc(sizeof(char *), ft_countword(s, c) + 1);
	if (!buffer)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			o = ft_word_len(s, c);
			buffer[i] = ft_substr(s, 0, o);
			if (!buffer[i])
				return (ft_purge_split(buffer, i));
			i++;
			s += o;
		}
		else
			s++;
	}
	return (buffer);
}
