/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 03:10:46 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/21 12:45:25 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>

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
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	rr;
	int	ra;
	int	rb;
	int	rrr;
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
t_vec2		a_find_prev(__int64_t val, int c);
t_vec2		a_find_next(__int64_t val, int c);
t_vec2		a_find_min(int c);
t_vec2		a_find_max(int c);
void		rotate_b_pile(t_p *p, t_vec2 v);
void		main_assign(t_p *p, t_vec2 rng[], t_vec2 rx);
int			*assign_range(t_vec2 v[], __int64_t size);
void		final_push(t_p *p);
//finder
int			ra_is_better(t_p *p);
int			is_in_range(t_vec2 v, int index);
//sort
void		sort_five(void);
void		sort_four(void);
void		sort_three(void);
void		main_algo(void);
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
#endif