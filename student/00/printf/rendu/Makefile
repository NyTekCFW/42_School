# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchiva <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 03:53:52 by lchiva            #+#    #+#              #
#    Updated: 2023/10/25 22:29:35 by lchiva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_printf_string.c ft_printf_convert.c ft_printf.c

NAME =	libftprintf.a

OBJS =	${SRCS:.c=.o}

CC =	gcc
RM =	rm -f
CFLAGS = -Wall -Wextra -Werror -I.

%.o: %.c
		$(CC) $(CFLAGS) $< -c -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)
clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

norme:
	@norminette $(SRCS) $(BONUS)

.PHONY:	all clean fclean re norme