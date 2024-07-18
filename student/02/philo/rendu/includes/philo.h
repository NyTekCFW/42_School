/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:42:26 by lchiva            #+#    #+#             */
/*   Updated: 2024/07/09 21:42:38 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

enum e_mutex
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY
};

enum e_philo_status
{
	ALIVE	= 0,
	DEAD,
	EAT_MAX,
	MAX
};
typedef struct arg_s
{
	int						nb_philos;
	int						die_time;
	int						eat_time;
	int						sleep_time;
	int						max_meals;
	int						nb_p_finish;
	int						stop;
	__int64_t				started;
	pthread_mutex_t			mutex_write;
	pthread_mutex_t			mutex_dead;
	pthread_mutex_t			mutex_eat_time;
	pthread_mutex_t			mutex_is_full;
}	t_arg;

typedef struct s_philo
{
	int						is_full;
	int						id;
	__uint32_t				nb_meals;
	__int64_t				time_last_meal;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*r_fork;
	pthread_mutex_t			l_fork;
	t_arg					*pa;
}	t_philo;

typedef struct s_p
{
	t_philo					*ph;
	t_arg					a;
}	t_p;

//philo_utils
void		solo_act(t_p *p);
void		__exit(char *str);
void		malloc_handler(void **ptr, size_t size);
//memory
void		*xmemcpy(void *dest, const void *src, size_t n);
void		*xmemset(void *s, int c, size_t n);
void		*xcalloc(size_t nmemb, size_t size);
void		xfree(void **data);
int			xalloc(void **var, size_t nmemb, size_t ts);
//string
int			isdigit(int c);
int			issymbol(int c);
__int64_t	xatoi(const char *n);
//clock
__int64_t	gettime(void);
void		__sleep(long wait);
//check
_Bool		check_argc(int argc);
_Bool		check_input(int argc, char **argv);
//mutex
void		set_mutex(int status, pthread_mutex_t *mutex);
void		init_mutex(t_p *p);
//thread
int			init_thread(t_p *p);
int			set_philo_status(t_philo *ph, int i);
//routine
void		activity(t_philo *ph);
void		print_status(char *str, t_philo *ph);
#endif