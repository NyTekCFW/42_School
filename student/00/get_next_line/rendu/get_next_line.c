/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 07:40:54 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/02 21:50:56 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_read(int fd, char *stack)
{
	ssize_t	bread;
	char	*buffer;

	bread = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bread != 0 && !ft_strchr(stack, '\n'))
	{
		bread = read(fd, buffer, BUFFER_SIZE);
		if (bread == -1)
			return (free(buffer), NULL);
		buffer[bread] = '\0';
		stack = ft_strjoin(stack, buffer);
	}
	return (free(buffer), stack);
}

char	*before_nl(char *stack)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!stack[0])
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	str = malloc((sizeof(char) * i) + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		str[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		str[i] = stack[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*after_nl(char *stack)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (!stack[i])
		return (free(stack), NULL);
	str = (char *)malloc(sizeof(char) * ((ft_strlen(stack) - i) + 1));
	if (!str)
		return (NULL);
	i++;
	while (stack[i])
		str[j++] = stack[i++];
	str[j] = '\0';
	return (free(stack), str);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(stack), stack = NULL, NULL);
	stack = gnl_read(fd, stack);
	if (!stack)
		return (NULL);
	line = before_nl(stack);
	stack = after_nl(stack);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("result = %s", str);
	if (str)
		free(str);
	str = get_next_line(fd);
	printf("result = %s", str);
	if (str)
		free(str);
	str = get_next_line(fd);
	printf("result = %s", str);
	if (str)
		free(str);
	return (0);
}
/*
int	main(void)
{
	char	*cs;
	int		fd;
	int		x;

	x = 0;
	fd = open("../rendu/out.txt", O_RDONLY);
	cs = NULL;
	if (fd > 0)
	{
		while (x < 6)
		{
		cs = get_next_line(fd);
		if (cs)
		{
			printf("out : %s\n", cs);
			free(cs);			
		}
		x++;
		}
	}
	return (0);
}
*/
