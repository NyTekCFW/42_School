/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 01:42:52 by lchiva            #+#    #+#             */
/*   Updated: 2024/02/13 15:40:41 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBG_H
# define DBG_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/ptrace.h>
# include <sys/wait.h>
# include <unistd.h>
# include <sys/user.h>
# include <ncurses.h>
# include <string.h>


enum e_cheat
{
	p_god		= 0,
	p_collect,
	p_max
};

struct s_var
{
	int	god;
	int	collected;
};

struct s_code
{
	long	offset;
	long	off_value;
	long	on_value;
};

typedef struct rev_s
{
	pid_t					pid;
	struct user_regs_struct	regs;
	char					path[256];
	long					base_adr;
	int						status;
	struct s_var			var;
	struct s_code			cheat[2];
}	t_rev;



enum e_addr
{
	addr_exit = 0x35BD,
	addr_max
};

int	init_ihm(t_rev *rev);
int	read_memory(t_rev *rev, long adr, long size);
int	write_memory(t_rev *rev, long adr, long val);

#endif