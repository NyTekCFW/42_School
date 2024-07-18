/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:03:25 by lchiva            #+#    #+#             */
/*   Updated: 2024/07/10 02:02:46 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/// @brief exit with a error
/// @param str string
void	__exit(char *str)
{
	printf("Error : %s\n", str);
	exit(1);
}

/// @brief called if only 1 philo
///exist
/// @param p main struct
void	solo_act(t_p *p)
{
	printf("1 Philo 1 has taken a fork\
\n%i Philo 1 die\n", p->a.die_time);
}

/// @brief make a memory alloc
///if fail __exit is call with a error
/// @param ptr char *m; (void **)&m
/// @param size size to allocate
void	malloc_handler(void **ptr, size_t size)
{
	if (!xalloc(ptr, size, 1))
		__exit("Malloc failed allocating memory");
}
