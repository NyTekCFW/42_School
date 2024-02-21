/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:10:36 by lchiva            #+#    #+#             */
/*   Updated: 2023/11/08 06:36:31 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert(char s, va_list *args, size_t *len, size_t *i)
{
	if (s == 's')
		ft_convert_str(va_arg(*args, char *), len);
	else if (s == 'c')
		ft_pf_c_insert(va_arg(*args, int), len);
	else if (s == '%')
		ft_pf_c_insert('%', len);
	else if (s == 'i' || s == 'd')
		ft_convert_int(va_arg(*args, int), len);
	else if (s == 'x' || s == 'X')
		ft_convert_hex(va_arg(*args, unsigned int), s, len);
	else if (s == 'u')
		ft_convert_uint(va_arg(*args, unsigned int), len);
	else if (s == 'p')
		ft_convert_ptr(va_arg(*args, size_t), len);
	else
		(*i)--;
}

int	ft_printf(const char *fmt, ...)
{
	size_t	index;
	size_t	ilen;
	va_list	args;

	ilen = 0;
	index = 0;
	va_start(args, fmt);
	while (fmt[index])
	{
		if (fmt[index] == '%')
		{
			index++;
			ft_convert(fmt[index], &args, &ilen, &index);
		}
		else
			ft_pf_c_insert(fmt[index], &ilen);
		index++;
	}
	va_end(args);
	return (ilen);
}
