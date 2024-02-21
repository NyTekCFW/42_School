/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:14:14 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/19 23:35:53 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>
/*
# define FT_UINT64_MAX (unsigned long)0xFFFFFFFFFFFFFFFF
# define FT_UINT64_MIN (unsigned long)0x00

# define FT_INT64_MAX (signed long)0x7FFFFFFFFFFFFFFF
# define FT_INT64_MIN (signed long)0x8000000000000000

# define FT_UINT_MAX (unsigned int)0xFFFFFFFF
# define FT_UINT_MIN (unsigned int)0x00

# define FT_INT_MAX (signed int)0x7FFFFFFF
# define FT_INT_MIN (signed int)0x80000000

# define FT_USHORT_MAX (unsigned short)0xFFFF
# define FT_USHORT_MIN (unsigned short)0x00

# define FT_SHORT_MAX (signed short)0x7FFF
# define FT_SHORT_MIN (signed short)0x8000

# define FT_UCHAR_MAX (unsigned int)0xFF
# define FT_UCHAR_MIN (unsigned int)0x00

# define FT_CHAR_MAX (signed char)0x7F
# define FT_CHAR_MIN (signed char)0x80
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
//math
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
//string
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
//memory
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_lstsize(t_list *lst);
void	ft_bzero(void *s, size_t n);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif