/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:43:28 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/16 19:14:01 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buffer;
	int		index;

	index = 0;
	if (!s || !f)
		return (NULL);
	buffer = (char *)ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!buffer)
		return (NULL);
	while (s[index])
	{
		buffer[index] = f(index, s[index]);
		index++;
	}
	return (buffer);
}
