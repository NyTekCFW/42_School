/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:24:30 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/14 02:16:15 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <stdarg.h>
# include <signal.h>
# include <bits/types/siginfo_t.h>
# include <bits/siginfo-consts.h>

typedef struct sig_s
{
	int				out_char;
	int				pow;
	int				mask;
	unsigned int	uid;
	char			*stack;
}	t_sig;

int		mt_print_str(char *str);
void	mt_putnbr(int nb);
int		mt_atoi(const char *str);
char	*mt_strjoin(char *s1, char s2);
size_t	mt_strlen(char *str);
void	*mt_memset(void *s, int c, size_t n);
#endif
