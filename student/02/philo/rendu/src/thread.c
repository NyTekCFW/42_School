/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:10 by lchiva            #+#    #+#             */
/*   Updated: 2024/07/10 03:09:09 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/// @brief set philo status
///if status is not ALIVE
///then the software stop
/// @param ph current philo
/// @param i ALIVE | DEAD | EAT_MAX
/// @return 1 or 0
int	set_philo_status(t_philo *ph, int i)
{
	set_mutex(LOCK, &ph->pa->mutex_dead);
	if (i != ALIVE)
		ph->pa->stop = i;
	if (ph->pa->stop)
	{
		set_mutex(UNLOCK, &ph->pa->mutex_dead);
		return (1);
	}
	set_mutex(UNLOCK, &ph->pa->mutex_dead);
	return (0);
}

/// @brief check status
/// @param data t_philo * current philo
static void	*is_dead(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	__sleep(ph->pa->die_time + 1);
	set_mutex(LOCK, &ph->pa->mutex_eat_time);
	set_mutex(LOCK, &ph->pa->mutex_is_full);
	if (!set_philo_status(ph, ALIVE) && !ph->is_full
		&& ((gettime() - ph->time_last_meal) \
		>= (long)(ph->pa->die_time)))
	{
		set_mutex(UNLOCK, &ph->pa->mutex_eat_time);
		set_mutex(UNLOCK, &ph->pa->mutex_is_full);
		set_mutex(LOCK, &ph->pa->mutex_write);
		print_status("died\n", ph);
		set_mutex(UNLOCK, &ph->pa->mutex_write);
		set_philo_status(ph, DEAD);
	}
	else
	{
		pthread_mutex_unlock(&ph->pa->mutex_eat_time);
		pthread_mutex_unlock(&ph->pa->mutex_is_full);
	}
	return (NULL);
}

/// @brief run activity
/// @param data t_philo * current philo
static void	*thread_run(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	if (ph->id % 2 == 0)
		__sleep(ph->pa->eat_time / 10);
	while (!set_philo_status(ph, ALIVE))
	{
		pthread_create(&ph->thread_death_id, NULL, is_dead, data);
		activity(ph);
		pthread_detach(ph->thread_death_id);
		if ((int)++ph->nb_meals == ph->pa->max_meals)
		{
			set_mutex(LOCK, &ph->pa->mutex_is_full);
			ph->is_full = 1;
			ph->pa->nb_p_finish++;
			if (ph->pa->nb_p_finish == ph->pa->nb_philos)
				set_philo_status(ph, EAT_MAX);
			set_mutex(UNLOCK, &ph->pa->mutex_is_full);
			return (NULL);
		}
	}
	return (NULL);
}

/// @brief start thread
///for each philosopher
///and do a ptr of p->a
///registered into the
///current philo struct
///to get an common access
/// @param p main struct
/// @return 1 or 0
int	init_thread(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->a.nb_philos)
	{
		p->ph[i].pa = &p->a;
		if (pthread_create(&p->ph[i].thread_id, 0, thread_run, &p->ph[i]) != 0)
		{
			__exit("Pthread did not return 0\n");
			return (0);
		}
		i++;
	}
	return (1);
}
