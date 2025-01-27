/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:10:27 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:37:07 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/_phone.hpp"
#include "../includes/PhoneBook.hpp"

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

static __uint32_t	get_cmd(void)
{
	__uint32_t	val;
	char		buffer[10];

	memset(buffer, 0, 10);
	std::cout << "> ";
	std::cin.getline(buffer, sizeof(buffer));
	return (fnv1a_hash(buffer));
}

int	main(void)
{
	__uint32_t	u;
	PhoneBook	Book;

	while (1)
	{
		u = get_cmd();
		if (u == ADD)
		{
			Book.profile[Book.get_pos()].add_contact(Book.get_pos());
			Book.inc_pos();
		}
		else if (u == SEARCH)
			Book.print_contact();
		else if (u == EXIT)
			break ;
	}
	std::cout << "Good bye ;(" << std::endl;
}