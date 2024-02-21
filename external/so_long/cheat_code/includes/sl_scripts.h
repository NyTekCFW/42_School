/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_scripts.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:02:13 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/20 00:10:37 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_SCRIPTS
# define SL_SCRIPTS

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define BUFFER_SIZE 42

enum	e_flags
{
	p_god = (1 << 0),
	p_ufo
};

typedef struct gf_s
{
	void			(*(func))();
	unsigned long	name;
	struct gf_s		*next;
}	t_gf;

typedef struct gentity_s
{
	char			etype;
	unsigned int	health;
	unsigned int	flags;
}	t_gentity;

//memory
void			*sl_memset(void *s, int c, size_t n);
void			*sl_memcpy(void *dest, const void *src, size_t n);
//string
char			*sl_strjoin(char *s1, char *s2);
char			*sl_strchr(const char *s, int c);
size_t			sl_strlen(const char *str);
unsigned long	sl_hashstr(const char *str);
//terminal
char			*gnl(int fd);
//scripts
void			init_scripts(t_gf *sc_l);
t_gf			*add_scripts(t_gf *sc_l, void (*(func))(), char	*name);
void			execute_scripts(t_gentity *ent, t_gf *sc_l, char *argv);
//flags
void			flag_set(t_gentity *ent, unsigned int flag);
void			flag_clear(t_gentity *ent, unsigned int flag);
void			flag_print(char	*str, unsigned int status);
//gfsr
void			Gfsr_God_f(t_gentity *player);
void			Gfsr_Ufo_f(t_gentity *player);
void			Gfsr_setviewpos_f(t_gentity *player);
#endif