/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:37:34 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/25 22:40:35 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_convert_hex(unsigned int nbr, char c, size_t *length);
void	ft_convert_int(int nbr, size_t *length);
void	ft_convert_uint(unsigned int nbr, size_t *length);
void	ft_convert_ptr(size_t ptr, size_t *length);
void	ft_convert_str(char *str, size_t *length);
void	ft_pf_c_insert(int c, size_t *length);
void	ft_pf_str_insert(char *str, size_t *length);
void	ft_pt_bzero(void *s, size_t n);
int		ft_printf(const char *fmt, ...);

#endif