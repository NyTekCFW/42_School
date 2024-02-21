/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:41:28 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/19 19:14:30 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*backup_l;
	void	*cnt;

	if (!lst || !f || !del)
		return (0);
	new_list = NULL;
	backup_l = NULL;
	while (lst)
	{
		cnt = f(lst->content);
		new_list = ft_lstnew(cnt);
		if (!new_list)
		{
			del(cnt);
			ft_lstclear(&backup_l, del);
			return (0);
		}
		ft_lstadd_back(&backup_l, new_list);
		lst = lst->next;
	}
	return (backup_l);
}
