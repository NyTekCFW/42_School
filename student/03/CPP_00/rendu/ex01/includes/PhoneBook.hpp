/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:02:18 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:37:00 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
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
