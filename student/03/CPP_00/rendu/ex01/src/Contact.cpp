/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:09:38 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/26 01:59:31 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/_phone.hpp"
#include "../includes/Contact.hpp"

Contact::Contact(void)
{
	memset(this->_firstname, 0, 32);
	memset(this->_lastname, 0, 32);
	memset(this->_nickname, 0, 32);
	memset(this->_phonenumber, 0, 10);
	memset(this->_secret, 0, 64);
}

void	Contact::add_contact(int i)
{
	this->rm_contact();
	this->_set_firstname();
	this->_set_lastname();
	this->_set_nickname();
	this->_set_phonenumber();
	this->_set_secret();
	this->_index = i;
}

void Contact::rm_contact(void)
{
	memset(this->_firstname, 0, 32);
	memset(this->_lastname, 0, 32);
	memset(this->_nickname, 0, 32);
	memset(this->_phonenumber, 0, 10);
	memset(this->_secret, 0, 64);
}

void	Contact::_set_firstname(void)
{
	int	is_waitting;

	is_waitting = 1;
	while (is_waitting)
	{
		std::cout << "Enter a first name (max. 32 characters): ";
		std::cin.getline(this->_firstname, sizeof(this->_firstname));
		
		if (std::cin.fail() || std::cin.gcount() == sizeof(this->_firstname) - 1)
		{
			std::cin.clear();
			memset(this->_firstname, 0, 32);
			std::cout << "Error: First name too long. Please try again." << std::endl;
		}
		else if (this->_firstname[0] == '\0')
		{
			std::cin.clear();
			std::cout << "Error: Empty string. Please try again." << std::endl;
		}
		else
			is_waitting = 0;
	}
}

void	Contact::_set_lastname(void)
{
	int	is_waitting;

	is_waitting = 1;
	while (is_waitting)
	{
		std::cout << "Enter a last name (max. 32 characters): ";
		std::cin.getline(this->_lastname, sizeof(this->_lastname));
		if (std::cin.fail() || std::cin.gcount() == sizeof(this->_lastname) - 1)
		{
			std::cin.clear();
			memset(this->_lastname, 0, 32);
			std::cout << "Error: Last name too long. Please try again." << std::endl;
		}
		else if (this->_lastname[0] == '\0')
		{
			std::cin.clear();
			std::cout << "Error: Empty string. Please try again." << std::endl;
		}
		else
			is_waitting = 0;
	}
}

void	Contact::_set_nickname(void)
{
	int	is_waitting;

	is_waitting = 1;
	while (is_waitting)
	{
		std::cout << "Enter a nickname (max. 32 characters): ";
		std::cin.getline(this->_nickname, sizeof(this->_nickname));
		if (std::cin.fail() || std::cin.gcount() == sizeof(this->_nickname) - 1)
		{
			std::cin.clear();
			memset(this->_nickname, 0, 32);
			std::cout << "Error: Nickname too long. Please try again." << std::endl;
		}
		else if (this->_nickname[0] == '\0')
		{
			std::cin.clear();
			std::cout << "Error: Empty string. Please try again." << std::endl;
		}
		else
			is_waitting = 0;
	}
}

void	Contact::_set_phonenumber(void)
{
	int	i;
	int	is_waitting;

	is_waitting = 1;
	i = 0;
	while (is_waitting)
	{
		std::cout << "Enter a phone number (max. 10 digits): ";
		std::cin.getline(this->_phonenumber, sizeof(this->_phonenumber));
		if ((std::cin.fail()) || (std::cin.gcount() == sizeof(this->_phonenumber) - 1))
		{
			std::cin.clear();
			memset(this->_phonenumber, 0, 10);
			std::cout << "Error: phone number too long. Please try again." << std::endl;
			continue ;
		}
		else if (this->_phonenumber[0] == '\0')
		{
			std::cin.clear();
			std::cout << "Error: Empty string. Please try again." << std::endl;
			continue ;
		}
		i = 0;
		while (this->_phonenumber[i])
		{
			if ((this->_phonenumber[i] < '0') || (this->_phonenumber[i] > '9'))
			{
				std::cin.clear();
				memset(this->_phonenumber, 0, 10);
				std::cout << "Error: a non-digit character was found. Please try again." << std::endl;
				continue ;
			}
			i++;
		}
		is_waitting = 0;
	}
}

void	Contact::_set_secret(void)
{
	int	is_waitting;

	is_waitting = 1;
	while (is_waitting)
	{
		std::cout << "Enter his darkest secret (max. 64 characters): ";
		std::cin.getline(this->_secret, sizeof(this->_secret));
		if (std::cin.fail() || std::cin.gcount() == sizeof(this->_secret) - 1)
		{
			std::cin.clear();
			memset(this->_secret, 0, 64);
			std::cout << "Error: Darkest secret too long. Please try again." << std::endl;
		}
		else if (this->_secret[0] == '\0')
		{
			std::cin.clear();
			std::cout << "Error: Empty string. Please try again." << std::endl;
		}
		else
			is_waitting = 0;
	}
}

Contact::~Contact(void)
{
	memset(this->_firstname, 0, 32);
	memset(this->_lastname, 0, 32);
	memset(this->_nickname, 0, 32);
	memset(this->_phonenumber, 0, 10);
	memset(this->_secret, 0, 64);
	this->_index = 0;
}
