/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:44:38 by lchiva            #+#    #+#             */
/*   Updated: 2024/07/09 21:41:35 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/// @brief lock the death mutex
/// check if stop is not true
/// unlock and return false
/// if the software is still
/// running
/// @param p main struct
/// @return 1 or 0
static int	check_is_dead(t_p *p)
{
	set_mutex(LOCK, &p->a.mutex_dead);
	if (p->a.stop)
	{
		set_mutex(UNLOCK, &p->a.mutex_dead);
		return (1);
	}
	set_mutex(UNLOCK, &p->a.mutex_dead);
	return (0);
}

/// @brief stop all philos
/// stop all philo thread
/// via pthread_join,
/// destroy all mutex
/// and free p->ph
/// @param p main struct
static void	stop_philo(t_p *p)
{
	int	i;

	i = 0;
	while (!check_is_dead(p))
		__sleep(1);
	while (i < p->a.nb_philos)
	{
		pthread_join(p->ph[i].thread_id, NULL);
		i++;
	}
	set_mutex(DESTROY, &p->a.mutex_write);
	i = 0;
	while (i < p->a.nb_philos)
	{
		set_mutex(DESTROY, &p->ph[i].l_fork);
		i++;
	}
	if (p->a.stop == EAT_MAX)
		printf("Each philosopher ate %d time(s)\n", p->a.max_meals);
	xfree((void **)&p->ph);
}

/// @brief init all philo data
/// @param p main struct
/// @return true
static int	init_philo(t_p *p)
{
	int	i;

	i = 0;
	p->a.started = gettime();
	p->a.stop = 0;
	p->a.nb_p_finish = 0;
	init_mutex(p);
	while (i < p->a.nb_philos)
	{
		p->ph[i].id = i + 1;
		p->ph[i].time_last_meal = p->a.started;
		p->ph[i].nb_meals = 0;
		p->ph[i].is_full = 0;
		p->ph[i].r_fork = NULL;
		set_mutex(INIT, &p->ph[i].l_fork);
		if (i == p->a.nb_philos - 1)
			p->ph[i].r_fork = &p->ph[0].l_fork;
		else
			p->ph[i].r_fork = &p->ph[i + 1].l_fork;
		i++;
	}
	return (1);
}

/// @brief handle and register all
///arguments that make philo routine
/// @param argc arguments count
/// @param argv arguments variable
/// @param p main struct
/// @return true or false
static _Bool	init_data(int argc, char **argv, t_p *p)
{
	p->a.nb_philos = xatoi(argv[1]);
	p->a.die_time = xatoi(argv[2]);
	p->a.eat_time = xatoi(argv[3]);
	p->a.sleep_time = xatoi(argv[4]);
	p->a.max_meals = -1;
	if (argc == 6)
		p->a.max_meals = xatoi(argv[5]);
	if (p->a.nb_philos <= 0 || p->a.die_time <= 0 || p->a.eat_time <= 0
		|| p->a.sleep_time <= 0 || p->a.max_meals == 0)
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_p	p;

	if (check_input(argc, argv) && init_data(argc, argv, &p))
	{
		if (p.a.nb_philos == 1)
		{
			solo_act(&p);
			return (0);
		}
		malloc_handler((void **)&p.ph, sizeof(t_philo) * p.a.nb_philos);
		if (!init_philo(&p) || !init_thread(&p))
		{
			xfree((void **)&p.ph);
			return (0);
		}
		stop_philo(&p);
	}
	return (0);
}
