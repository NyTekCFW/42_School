/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:02:18 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/26 03:42:03 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
public:
	PhoneBook(void);
	Contact	profile[8];
	void inc_pos(void);
	void print_contact(void);
	static int	get_pos(void);
	~PhoneBook(void);
private:
	static int	_pos;
};

#endif