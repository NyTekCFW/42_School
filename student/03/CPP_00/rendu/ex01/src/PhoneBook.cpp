/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:05:32 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/26 04:41:19 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/_phone.hpp"
#include "../includes/PhoneBook.hpp"

static void welcome(void)
{
	std::cout << "Welcome to my PhonyBook Software 📞" << std::endl;
	std::cout << "------------COMMAND LIST------------" << std::endl;
	std::cout << "ADD = Add a contact" << std::endl;
	std::cout << "SEARCH = Search a contact" << std::endl;
	std::cout << "EXIT = Leave PhonyBook" << std::endl;
	std::cout << "------------------------------------" << std::endl;
}

PhoneBook::PhoneBook(void)
{
	welcome();
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

static void	asset_data(char *dest, char *src)
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
	char	index[11];
	char	name[11];
	char	last[11];
	char	nick[11];
	char	entry[11];
	i = 0;
	std::cout << "------------- PHONEBOOK CONTACTS ------------" << std::endl;
	while (i < 8)
	{
		if (this->profile[i].getfirstname()[0] == '\0')
			break ;
		std::cout << "|";
		memset(index, 0x20, 11);
		index[9] = 0x30 + i;
		index[10] = '\0';
		std::cout << index << "|";
		asset_data(name, this->profile[i].getfirstname());
		std::cout << name << "|";
		asset_data(last, this->profile[i].getlastname());
		std::cout << last << "|";
		asset_data(nick, this->profile[i].getnickname());
		std::cout << nick << "|" << std::endl; 
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl;
	if (i == 0)
	{
		std::cout << "No contact(s) found" << std::endl;
		return ;
	}
	memset(entry, 0, 11);
	std::cout << "Enter a index : ";
	std::cin.getline(entry, sizeof(entry));
	if (strlen(entry) == 1 && entry[0] >= '0' && entry[0] <= '9' && entry[0] < 0x30 + i)
	{
		std::cout << "First Name     : " << this->profile[entry[0] - 0x30].getfirstname() << std::endl;
		std::cout << "Last Name      : " << this->profile[entry[0] - 0x30].getlastname() << std::endl;
		std::cout << "Nickname       : " << this->profile[entry[0] - 0x30].getnickname() << std::endl;
		std::cout << "Phone Number   : " << this->profile[entry[0] - 0x30].getphonenumber() << std::endl;
		std::cout << "Darkest Secret : " << this->profile[entry[0] - 0x30].getsecret() << std::endl;
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