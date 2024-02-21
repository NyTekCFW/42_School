/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 01:42:36 by lchiva            #+#    #+#             */
/*   Updated: 2024/02/13 16:10:33 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dbg.h"

int	get_config2(t_rev *rev, char *line, char *key, int i)
{
	if (sscanf(line, "%s", key) != 1)
	{
		fprintf(stderr, "Erreur de lecture de la clé\n");
		return (0);
	}
	if (!strcmp(key, "offset"))
		sscanf(line, "%*s = %lx;", &rev->cheat[i].offset);
	else if (!strcmp(key, "off"))
		sscanf(line, "%*s = %lx;", &rev->cheat[i].off_value);
	else if (!strcmp(key, "on"))
		sscanf(line, "%*s = %lx;", &rev->cheat[i].on_value);
	return (1);
}

int	get_config(t_rev *rev, char *path_file)
{
	char	line[256];
	char	key[256];
	FILE	*file;
	int		i;

	i = -1;
	file = fopen(path_file, "r");
	if (file == NULL)
	{
		perror("Impossible d'ouvrir le fichier de configuration");
		return (0);
	}
	while (fgets(line, 256, file))
	{
		if (line[0] == '\n' || line[0] == '#' || line[0] == '[')
		{
			if (line[0] == '[' && i < 1)
				i++;
			continue ;
		}
		if (!get_config2(rev, line, key, i))
			break ;
	}
	fclose(file);
	return (1);
}

int	dg_find_proc(t_rev *rev)
{
	FILE	*maps_file;
	char	line[512];
	char	*start_address;
	int		s;

	s = 0;
	maps_file = fopen(rev->path, "r");
	if (maps_file == NULL)
	{
		perror("fopen");
		return (s);
	}
	while (fgets(line, sizeof(line), maps_file))
	{
		if (strstr(line, "r-xp") != NULL)
		{
			start_address = strtok(line, "-");
			rev->base_adr = strtoul(start_address, NULL, 16);
			s = 1;
			break ;
		}
	}
	fclose(maps_file);
	return (s);
}

int	dg_attach(t_rev *rev, char **argv)
{
	rev->pid = atoi(argv[1]);
	if (ptrace(PTRACE_ATTACH, rev->pid, NULL, NULL) == -1)
	{
		perror("ptrace attach");
		return (0);
	}
	snprintf(rev->path, sizeof(rev->path), "/proc/%d/maps", rev->pid);
	waitpid(rev->pid, &rev->status, 0);
	if (WIFEXITED(rev->status))
	{
		printf("Process %d has already exited->\n", rev->pid);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_rev	rev;

	memset(&rev, 0, sizeof(rev));
	if (argc != 3)
	{
		printf("Usage : ./Trainer <PID so_long> re_sl/<creator>.txt");
		return (0);
	}
	if (dg_attach(&rev, argv))
	{
		write(1, "Trainer Attached to So_Long\n", 28);
		if (dg_find_proc(&rev))
		{
			write(1, "So_Long proc finded!\n", 21);
			if (get_config(&rev, argv[2]))
				init_ihm(&rev);
		}
		if (ptrace(PTRACE_DETACH, rev.pid, NULL, NULL) == -1)
		{
			perror("ptrace detach");
			return (1);
		}
	}
}

//cc main.c ihm.c memory.c -lncurses
