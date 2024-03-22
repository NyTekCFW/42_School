/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:10:48 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/16 01:10:50 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

__uint32_t	xhashstr(const char *str)
{
	__uint32_t	hash;

	hash = 2784;
	while (*str++)
		hash = ((hash << 5) + hash) + (int)*str;
	return (hash);
}

int	xstrcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1++ == *s2++)
		;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

size_t	xstrlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print(char *str)
{
	int		i;
	size_t	len;

	len = xstrlen(str);
	i = STDOUT_FILENO;
	if (len > 6 && str[5] == ':' && str[4] == 'r' && str[0] == 'E')
		i = STDERR_FILENO;
	write(i, str, len);
	if (str[len - 1] != '\n')
		write(i, "\n", 1);
}

char	*xstrjoin(char **s1, char *s2)
{
	char	*new_c;
	size_t	s[2];

	if (!*s1 && !xalloc((void **)&*s1, 1, sizeof(char)))
		return (NULL);
	if (!s2 || !*s2)
		return (*s1);
	xmemcpy(s, (size_t []){xstrlen(*s1), xstrlen(s2)}, 2 * sizeof(size_t));
	if (xalloc((void **)&new_c, s[0] + s[1] + 1, sizeof(char)))
	{
		xmemcpy(new_c, *s1, s[0]);
		xmemcpy(new_c + s[0], s2, s[1]);
		return (free(*s1), *s1 = new_c, *s1);
	}
	return (*s1);
}
