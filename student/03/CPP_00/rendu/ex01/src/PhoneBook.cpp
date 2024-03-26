/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:05:32 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/26 01:54:07 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/_phone.hpp"
#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{

}

void PhoneBook::inc_pos(void)
{
	if (this->PhoneBook::_pos > 8)
		this->PhoneBook::_pos = 0;
	else
		this->PhoneBook::_pos++;
}

int	PhoneBook::get_pos(void)
{
	return PhoneBook::_pos;
}

int	PhoneBook::_pos = 0;

PhoneBook::~PhoneBook(void)
{
	this->PhoneBook::_pos = 0;
}