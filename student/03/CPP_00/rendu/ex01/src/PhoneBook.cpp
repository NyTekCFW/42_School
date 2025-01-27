/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:05:32 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:37:10 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/_phone.hpp"
#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Welcome to my PhonyBook Software 📞" << std::endl;
	std::cout << "------------  <USAGE>  ------------" << std::endl;
	std::cout << "ADD = Add a contact" << std::endl;
	std::cout << "SEARCH = Search a contact" << std::endl;
	std::cout << "EXIT = Leave PhonyBook" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

void PhoneBook::inc_pos(void)
{
	if (this->PhoneBook::_pos >= 7)
		this->PhoneBook::_pos = 0;
	else
		this->PhoneBook::_pos++;
}

int	PhoneBook::get_pos(void)
{
	return PhoneBook::_pos;
}

static void	asset_data(char *dest, const char *src)
{
	size_t	len;
	len = strlen(src);
	if (len < 10)
		memset(dest, 0x20, 11 - len);
	else
		memcpy(dest, src, 10);
	if (len >= 10)
		dest[9] = '.';
	else
		memcpy(dest + 10 - len, src, len);
	dest[10] = '\0';
}

void	PhoneBook::print_contact(void)
{
	int		i;
	std::string	buffer;
	char		index[11];
	char		name[11];
	char		last[11];
	char		nick[11];
	i = 0;
	std::cout << "------------- PHONEBOOK CONTACTS ------------" << std::endl;
	while (i < 8)
	{
		if (this->profile[i].get_data(i_firstname).length() == 0
			|| this->profile[i].get_data(i_firstname).data()[0] == '\0')
			break ;
		std::cout << "|";
		memset(index, 0x20, 11);
		index[9] = 0x30 + i;
		index[10] = '\0';
		std::cout << index << "|";
		asset_data(name, this->profile[i].get_data(i_firstname).data());
		std::cout << name << "|";
		asset_data(last, this->profile[i].get_data(i_lastname).data());
		std::cout << last << "|";
		asset_data(nick, this->profile[i].get_data(i_nickname).data());
		std::cout << nick << "|" << std::endl; 
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl;
	if (i == 0)
	{
		std::cout << "No contact(s) found" << std::endl;
		return ;
	}
	std::cout << "Enter a index : ";
	std::getline(std::cin, buffer);
	if (strlen(buffer.data()) == 1 && buffer.data()[0] >= '0' && buffer.data()[0] <= '9' && buffer.data()[0] < 0x30 + i)
	{
		i = buffer.data()[0] - 0x30;
		std::cout << "First Name     : " << this->profile[i].get_data(i_firstname).data() << std::endl;
		std::cout << "Last Name      : " << this->profile[i].get_data(i_lastname).data() << std::endl;
		std::cout << "Nickname       : " << this->profile[i].get_data(i_nickname).data() << std::endl;
		std::cout << "Phone Number   : " << this->profile[i].get_data(i_phone).data() << std::endl;
		std::cout << "Darkest Secret : " << this->profile[i].get_data(i_secret).data() << std::endl;
	}
	else
	{
		std::cin.clear();
		std::cout << "Bad index reference!" << std::endl;
	}
}

int	PhoneBook::_pos = 0;

PhoneBook::~PhoneBook(void)
{
	this->PhoneBook::_pos = 0;
}