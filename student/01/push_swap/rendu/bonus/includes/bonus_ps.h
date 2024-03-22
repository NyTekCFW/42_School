/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:58:08 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/22 19:13:42 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PS_H
# define BONUS_PS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>

# define BUFFER_SIZE 42

enum e_act
{
	act_get	= 0,
	act_init,
	act_free,
	act_max
};

enum e_pile
{
	pile_a	= 0,
	pile_b,
	pile_max
};

typedef struct cmd_s
{
	__uint32_t	hash;
	void		(*(func))();
}	t_cmd;

typedef struct vec2_s
{
	__int64_t	x;
	__int64_t	y;
}	t_vec2;

typedef struct pile_s
{
	__int64_t		val;
	int				index;
	size_t			f_index;
	struct pile_s	*next;
}	t_pile;

typedef struct p_s
{
	t_pile		*pile[2];
	size_t		size;
	__int64_t	p_size[2];
	__int64_t	*tab_entry;
	__int64_t	*sorted_entry;
	char		*joined;
	char		**splitted;
	int			*range_sizes;
	t_cmd		cmd[12];
}	t_p;

//memory
void		*xmemcpy(void *dest, const void *src, size_t n);
void		*xcalloc(size_t nmemb, size_t size);
void		*xmemset(void *s, int c, size_t n);
int			xalloc(void **var, size_t nmemb, size_t ts);
void		xfree(void **data);
//string
__uint32_t	xhashstr(const char *str);
int			xstrcmp(const char *s1, const char *s2);
size_t		xstrlen(char *str);
void		print(char *str);
char		*xstrjoin(char **s1, char *s2);
char		**xsplit(char *s, char c, size_t *ts);
void		insert_str(char *buffer, char *str, size_t bs);
char		*xsubstr(char *s, unsigned int start, size_t len);
int			isdigit(int c);
int			issymbol(int c);
__int64_t	xatoi(const char *n);
int			xsort(__int64_t tab[], __int64_t size);
int			is_sorted(int x);
void		xputnbr(__int64_t n);
char		*gnl(int fd);
//check
int			check_parsing(int argc, char **argv);
//pile
void		sort_type(void);
t_p			*get_piles(int act);
void		insert_to_pile_a(void);
t_pile		*find_prev_pile(int a, t_pile *ptr);
t_pile		*get_last_pile(int a);
void		re_attribute_index(int p);
void		print_pile(int p);
//swap
void		sa(void);
void		sb(void);
void		ss(void);
void		pa(void);
void		pb(void);
void		rr(void);
void		rb(void);
void		ra(void);
void		rra(void);
void		rrb(void);
void		rrr(void);
//cmds
int			find_and_execute(t_p *p, char *cmd);
void		init_cmds(t_p *p);
#endif