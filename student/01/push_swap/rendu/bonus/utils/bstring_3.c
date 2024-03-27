/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstring_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:02:48 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/26 20:13:17 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_ps.h"

static __uint32_t	fnv1a_hash(const char *str)
{
	__uint32_t	hash;

	hash = 2166136261u;
	while (*str)
	{
		hash ^= (unsigned char)*str++;
		hash *= 16777619u;
	}
	return (hash);
}

static void	inject_cmds(t_p *p, char *n, void (*(func))(), int *i)
{
	p->cmd[*i].hash = fnv1a_hash(n);
	p->cmd[*i].func = func;
	*i += 1;
}

void	init_cmds(t_p *p)
{
	int	i;

	i = 0;
	inject_cmds(p, "sa\n", sa, &i);
	inject_cmds(p, "sb\n", sb, &i);
	inject_cmds(p, "ss\n", ss, &i);
	inject_cmds(p, "pa\n", pa, &i);
	inject_cmds(p, "pb\n", pb, &i);
	inject_cmds(p, "rr\n", rr, &i);
	inject_cmds(p, "ra\n", ra, &i);
	inject_cmds(p, "rb\n", rb, &i);
	inject_cmds(p, "rra\n", rra, &i);
	inject_cmds(p, "rrb\n", rrb, &i);
	inject_cmds(p, "rrr\n", rrr, &i);
}

char	*gnl(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE > 42)
		return (NULL);
	if (xalloc((void **)&line, BUFFER_SIZE, sizeof(char)))
	{
		read(fd, line, BUFFER_SIZE);
		return (line);
	}
	return (NULL);
}

int	find_and_execute(t_p *p, char *cmd)
{
	__uint32_t	hashname;
	int			i;

	i = 0;
	if (!cmd)
		return (0);
	hashname = fnv1a_hash(cmd);
	while (i < 12)
	{
		if (p->cmd[i].hash == hashname)
			return (p->cmd[i].func(), 1);
		i++;
	}
	if (hashname != fnv1a_hash("\n")
		&& hashname != fnv1a_hash(""))
		return (-1);
	return (0);
}
