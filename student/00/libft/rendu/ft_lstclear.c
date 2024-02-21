/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:09:31 by lchiva            #+#    #+#             */
/*   Updated: 2023/10/18 00:03:55 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*atm;
	t_list	*next;

	atm = *lst;
	if (!del || !lst || !*lst)
		return ;
	while (atm != NULL)
	{
		next = atm->next;
		(*del)(atm->content);
		free(atm);
		atm = next;
	}
	*lst = NULL;
}
