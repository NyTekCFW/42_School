/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:00:09 by lchiva            #+#    #+#             */
/*   Updated: 2024/07/09 18:57:14 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/// @brief get current time in ms
/// @return current time
__int64_t	gettime(void)
{
	struct timeval	time;
	__int64_t		clock;

	if (gettimeofday(&time, NULL) == -1)
		__exit("gettimeofday returned -1");
	clock = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (clock);
}

/// @brief sleep
/// @param wait time to wait in ms
///e.g: 1000 = 1sec
void	__sleep(long wait)
{
	__int64_t	p;

	p = gettime();
	while ((gettime() - p) < wait)
		usleep(wait / 10);
}
