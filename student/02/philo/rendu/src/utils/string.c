/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:59:08 by lchiva            #+#    #+#             */
/*   Updated: 2024/07/10 02:17:22 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/// @brief check if the current
///character is a digit
/// @param c character
/// @return 1 or 0
int	isdigit(int c)
{
	return (c >= 0x30 && c <= 0x39);
}

/// @brief check if the current
///character is a symbol + or -
/// @param c character
/// @return 1 or 0
int	issymbol(int c)
{
	return (((c == '-') || (c == '+')));
}

/// @brief transform a string that contain digit
///into the value in int64
/// @param n string
/// @return value in int64
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
