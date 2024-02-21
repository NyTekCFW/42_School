/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:14:57 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/21 23:21:39 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_sig	g_mtalk;

int	send_byte(int pid, int value)
{
	g_mtalk.mask = 128;
	while (g_mtalk.mask)
	{
		if (g_mtalk.mask & value)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (mt_print_str("Signal error!"), 0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (mt_print_str("Signal error!"), 0);
		}
		g_mtalk.mask /= 2;
		usleep(100);
	}
	return (1);
}

void	send_msg(int pid, char *msg)
{
	int	i;
	int	status;

	i = 0;
	status = 1;
	while (status && msg[i])
		status = send_byte(pid, msg[i++]);
	if (status)
	{
		send_byte(pid, '\n');
		send_byte(pid, '\0');
	}
}

void	receiv_sig(int signal)
{
	write(1, "Signal received: ", 17);
	mt_putnbr(signal);
	write(1, "\n\0", 2);
	g_mtalk.out_char = 0;
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_handler = receiv_sig;
	g_mtalk.stack = NULL;
	g_mtalk.mask = 128;
	g_mtalk.out_char = 0;
	g_mtalk.pow = 0;
	if (sigaction(SIGUSR2, &sig, 0) == -1
		||sigaction(SIGUSR1, &sig, 0) == -1)
		mt_print_str("Signal error!");
	if (argc == 3)
		send_msg(mt_atoi(argv[1]), argv[2]);
	else
		mt_print_str("error arguments!");
	return (0);
}
