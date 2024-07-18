/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:28:05 by lchiva            #+#    #+#             */
/*   Updated: 2024/07/10 02:48:48 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/// @brief sleep and think and write
///status
/// @param ph current philo
static void	sleep_think(t_philo *ph)
{
	set_mutex(LOCK, &ph->pa->mutex_write);
	print_status("is sleeping\n", ph);
	set_mutex(UNLOCK, &ph->pa->mutex_write);
	__sleep(ph->pa->sleep_time);
	set_mutex(LOCK, &ph->pa->mutex_write);
	print_status("is thinking\n", ph);
	set_mutex(UNLOCK, &ph->pa->mutex_write);
}

/// @brief change forks status
/// LOCK | UNLOCK
/// @param ph current philo
/// @param status LOCK | UNLOCK
static void	set_forks(t_philo *ph, int status)
{
	if (ph->id % 2 == 0)
	{
		set_mutex(status, &ph->l_fork);
		set_mutex(status, ph->r_fork);
	}
	else
	{
		set_mutex(status, ph->r_fork);
		set_mutex(status, &ph->l_fork);
	}
}

/// @brief print status of current philo
/// @param str string
/// @param ph current philo
void	print_status(char *str, t_philo *ph)
{
	__int64_t	t;

	t = gettime() - ph->pa->started;
	if (t >= 0 && t <= 2147483647 && !set_philo_status(ph, ALIVE))
	{
		printf("%ld ", t);
		printf("Philo %d %s", ph->id, str);
	}
}

/// @brief play activity for current philo
///take fork and write each status
/// @param ph current philo
void	activity(t_philo *ph)
{
	set_forks(ph, LOCK);
	set_mutex(LOCK, &ph->pa->mutex_write);
	print_status("has taken a fork\n", ph);
	print_status("has taken a fork\n", ph);
	set_mutex(UNLOCK, &ph->pa->mutex_write);
	if (!ph->r_fork)
	{
		__sleep(ph->pa->die_time * 2);
		return ;
	}
	set_mutex(LOCK, &ph->pa->mutex_write);
	print_status("is eating\n", ph);
	set_mutex(LOCK, &ph->pa->mutex_eat_time);
	ph->time_last_meal = gettime();
	set_mutex(UNLOCK, &ph->pa->mutex_eat_time);
	set_mutex(UNLOCK, &ph->pa->mutex_write);
	__sleep(ph->pa->eat_time);
	set_forks(ph, UNLOCK);
	sleep_think(ph);
}
