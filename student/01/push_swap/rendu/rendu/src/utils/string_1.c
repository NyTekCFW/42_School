/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:10:55 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/16 01:10:57 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	insert_str(char *buffer, char *str, size_t bs)
{
	size_t	i;

	i = 0;
	while (str[i] && i < bs)
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = 0;
}

char	*xsubstr(char *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = xstrlen(s);
	if (start > len_s)
		return (xcalloc(1, sizeof(char)));
	if (len > xstrlen(s + start))
		len = xstrlen(s + start);
	buffer = xcalloc(len + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	xmemcpy(buffer, &s[start], len);
	buffer[len] = '\0';
	return (buffer);
}

int	isdigit(int c)
{
	return (c >= 0x30 && c <= 0x39);
}

int	issymbol(int c)
{
	return (((c == '-') || (c == '+')));
}

__int64_t	xatoi(const char *n)
{
	__int64_t	i;
	__int64_t	res;
	__int64_t	mp;

	mp = 1;
	res = 0;
	i = 0;
	while (n[i] && ((n[i] >= 0x09 && n[i] <= 0x0D) || (n[i] == 0x20)))
		i++;
	if ((n[i] && n[i] == '+') || (n[i] && n[i] == '-'))
	{
		if (n[i] == '-')
			mp *= -1;
		i++;
	}
	while (n[i] && n[i] >= 0x30 && n[i] <= 0x39)
		res = (res * 10) + (n[i++] - 0x30);
	return (res * mp);
}
