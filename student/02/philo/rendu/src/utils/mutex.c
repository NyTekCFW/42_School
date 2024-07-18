/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:18:39 by lchiva            #+#    #+#             */
/*   Updated: 2024/07/09 21:41:04 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/// @brief change mutex status
/// @param status INIT | LOCK |
/// UNLOCK | DESTROY
/// @param mutex mutex to edit
void	set_mutex(int status, pthread_mutex_t *mutex)
{
	if (status == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (status == LOCK)
		pthread_mutex_lock(mutex);
	else if (status == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (status == DESTROY)
		pthread_mutex_destroy(mutex);
}

/// @brief initialize all
/// basics mutex for a philosopher
/// @param p current philosopher
void	init_mutex(t_p *p)
{
	pthread_mutex_init(&p->a.mutex_write, NULL);
	pthread_mutex_init(&p->a.mutex_dead, NULL);
	pthread_mutex_init(&p->a.mutex_eat_time, NULL);
	pthread_mutex_init(&p->a.mutex_is_full, NULL);
}
