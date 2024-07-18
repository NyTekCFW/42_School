/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:29:52 by lchiva            #+#    #+#             */
/*   Updated: 2024/07/09 21:28:33 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/// @brief display how to use
///properly philosopher
static void	_usage(void)
{
	printf("Usage :\n./philo <nb_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_spleep>\n");
	printf("[This argument is optional] <nb_of_meals>");
}

/// @brief display error
///if non-digit is found in args 
static void	digit_error(void)
{
	printf("Error : Incorrect(s) argument(s) detected\n");
	_usage();
}

/// @brief check arguments count
/// @param argc number of arguments
/// @return true or false
_Bool	check_argc(int argc)
{
	_Bool	o;

	o = true;
	if (argc < 5)
	{
		printf("Error : Missing at least %i arguments\n", 5 - argc);
		o = false;
	}
	else if (argc > 6)
	{
		printf("Error : Too many arguments\n");
		o = false;
	}
	if (!o)
		_usage();
	return (o);
}

/// @brief check argc and argv
/// @param argc arguments count
/// @param argv arguments variable
/// @return true or false
_Bool	check_input(int argc, char **argv)
{
	int	i;
	int	o;

	i = 1;
	o = 0;
	if (check_argc(argc))
	{
		while (argv[i])
		{
			o = 0;
			while (argv[i][o])
			{
				if (!isdigit(argv[i][o]))
				{
					digit_error();
					return (false);
				}
				o++;
			}
			i++;
		}
		return (true);
	}
	return (false);
}
