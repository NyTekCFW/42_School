/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:41:51 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/25 19:19:48 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_int(int nbr, size_t *length)
{
	if (nbr == -2147483648)
	{
		ft_pf_str_insert("-2147483648", length);
		return ;
	}
	if (nbr < 0)
	{
		ft_pf_c_insert('-', length);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_convert_int(nbr / 10, length);
		ft_convert_int(nbr % 10, length);
	}
	else
		ft_pf_c_insert(nbr % 10 + '0', length);
}

void	ft_convert_uint(unsigned int nbr, size_t *length)
{
	if (nbr >= 10)
		ft_convert_uint(nbr / 10, length);
	ft_pf_c_insert(nbr % 10 + '0', length);
}

void	ft_convert_ptr(size_t ptr, size_t *length)
{
	char	buffer[25];
	int		xs;
	char	*base;

	ft_pt_bzero(buffer, 25);
	if (!ptr)
	{
		ft_pf_str_insert("(nil)", length);
		return ;
	}
	base = "0123456789abcdef";
	ft_pf_str_insert("0x", length);
	xs = 0;
	while (ptr > 0)
	{
		buffer[xs++] = base[ptr % 16];
		ptr = ptr / 16;
	}
	while (xs--)
		ft_pf_c_insert(buffer[xs], length);
}

void	ft_convert_hex(unsigned int nbr, char c, size_t *length)
{
	char	buffer[25];
	char	*base;
	int		xs;

	ft_pt_bzero(buffer, 25);
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (!nbr)
	{
		ft_pf_c_insert('0', length);
		return ;
	}
	xs = 0;
	while (nbr != 0)
	{
		buffer[xs++] = base[nbr % 16];
		nbr = nbr / 16;
	}
	while (xs--)
		ft_pf_c_insert(buffer[xs], length);
}

void	ft_convert_str(char *str, size_t *length)
{
	if (!str)
	{
		ft_pf_str_insert("(null)", length);
		return ;
	}
	ft_pf_str_insert(str, length);
}
