/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:14:48 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/21 23:22:08 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_sig	g_mtalk;

void	reset_handler(siginfo_t *siginfo)
{
	free(g_mtalk.stack);
	g_mtalk.uid = siginfo->si_uid;
	g_mtalk.stack = NULL;
}

void	my_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	(void)ucontext;
	if (siginfo->si_uid != g_mtalk.uid)
		reset_handler(siginfo);
	if (signum == SIGUSR1)
		g_mtalk.out_char |= (1 << (7 - g_mtalk.pow));
	else
		g_mtalk.out_char &= ~(1 << (7 - g_mtalk.pow));
	g_mtalk.pow += 1;
	if (g_mtalk.pow == 8)
	{
		g_mtalk.pow = 0;
		g_mtalk.stack = mt_strjoin(g_mtalk.stack, (char)g_mtalk.out_char);
		if (!g_mtalk.stack)
			return (free(g_mtalk.stack), g_mtalk.stack = NULL, (void)0);
		if (g_mtalk.out_char == 0)
		{
			write(1, g_mtalk.stack, mt_strlen(g_mtalk.stack));
			free(g_mtalk.stack);
			g_mtalk.stack = NULL;
			if (kill(siginfo->si_pid, signum) == -1)
				mt_print_str("Signal error!");
		}
		g_mtalk.out_char = 0;
	}
}

void	exit_func(int signo)
{
	if (signo == SIGINT)
	{
		mt_print_str("\nDetected (Ctrl+C) - Stopping server\n");
		free(g_mtalk.stack);
		g_mtalk.stack = NULL;
		exit(0);
	}
}

int	main(void)
{
	struct sigaction	sig;

	write(1, "Serveur PID: ", 13);
	mt_putnbr(getpid());
	write(1, "\n", 1);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = my_handler;
	signal(SIGINT, exit_func);
	mt_memset(&g_mtalk, 0, sizeof(g_mtalk));
	g_mtalk.stack = (char *)malloc(sizeof(char) * 1);
	g_mtalk.stack[0] = '\0';
	if (sigemptyset(&sig.sa_mask) == -1
		|| sigaction(SIGUSR1, &sig, 0) == -1
		|| sigaction(SIGUSR2, &sig, 0) == -1)
		mt_print_str("Signal error!");
	while (1)
		;
	return (free(g_mtalk.stack), g_mtalk.stack = NULL, 0);
}
