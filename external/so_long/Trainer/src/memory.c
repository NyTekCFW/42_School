/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 03:00:01 by lchiva            #+#    #+#             */
/*   Updated: 2024/02/13 04:31:06 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dbg.h"

static long	reverse_memory(long data)
{
	long	reversed_data;
	int		nb;
	int		i;

	i = 0;
	nb = sizeof(long);
	reversed_data = 0;
	while (i < nb)
	{
		reversed_data |= ((data >> (i * 8)) & 0xFF) << ((nb - 1 - i) * 8);
		i++;
	}
	return (reversed_data);
}

int	read_memory(t_rev *rev, long adr, long size)
{
	long	data;
	long	i;

	i = 0;
	while (i < size)
	{
		data = ptrace(PTRACE_PEEKDATA, rev->pid,
				(rev->base_adr + adr + i), NULL);
		if (data == -1)
		{
			perror("ptrace peekdata");
			return (0);
		}
		data = reverse_memory(data);
		printf("%lx\n", data);
		i++;
	}
	write(1, "\n", 1);
	return (1);
}

int	write_memory(t_rev *rev, long adr, long val)
{
	long	rev_val;

	rev_val = reverse_memory(val);
	if (ptrace(PTRACE_POKEDATA, rev->pid,
			(rev->base_adr + adr), rev_val) == -1)
	{
		perror("ptrace pokedata");
		return (0);
	}
	return (1);
}
