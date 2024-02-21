/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:37:06 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/18 06:58:20 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_c_insert(int c, size_t *length)
{
	write(1, &c, 1);
	(*length)++;
}

void	ft_pf_str_insert(char *str, size_t *length)
{
	while (*str)
		ft_pf_c_insert(*str++, length);
}

void	ft_pt_bzero(void *s, size_t n)
{
	char	*c;

	c = s;
	while (n--)
		*c++ = 0;
}
