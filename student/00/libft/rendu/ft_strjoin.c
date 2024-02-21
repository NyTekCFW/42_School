/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 03:12:25 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/10 07:35:22 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	int		sz1;
	int		sz2;
	int		total;

	if (!s1 || !s2)
		return (NULL);
	sz1 = ft_strlen(s1);
	sz2 = ft_strlen(s2);
	total = sz1 + sz2 + 1;
	buffer = (char *)ft_calloc(total, sizeof(char));
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s1, sz1);
	ft_memcpy(&buffer[sz1], s2, sz2);
	buffer[sz1 + sz2] = '\0';
	return (buffer);
}
