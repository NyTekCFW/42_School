/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:09:38 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/27 02:16:22 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/_phone.hpp"
#include "../includes/Contact.hpp"

Contact::Contact(void)
{
	for (int i = 0; i < i_max; i++)
		this->info[i] = "";
}

void	Contact::add_contact(int i)
{
	this->rm_contact();
	this->info[i_firstname] = this->set_data("Enter first name: ");
	this->info[i_lastname] = this->set_data("Enter last name: ");
	this->info[i_nickname] = this->set_data("Enter nickname: ");
	this->info[i_phone] = this->set_data("Enter phone number: ");
	this->info[i_secret] = this->set_data("Enter darkest secret: ");
	this->_index = i;
}

void Contact::rm_contact(void)
{
	for (int i = 0; i < i_max; i++)
		this->info[i] = "";
}

std::string Contact::get_data(int id)
{
	return this->info[id];
}

std::string	Contact::set_data(const char *text)
{
	std::string	buffer;
	int	spec;
	int	is_waitting;

	is_waitting = 1;
	buffer = "";
	spec = 0;
	while (is_waitting)
	{
		std::cout <<  text;
		std::getline(std::cin, buffer);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Error: std::cin fail!" << std::endl;
		}
		else if (buffer.length() == 0 || buffer.data()[0] == '\0')
		{
			std::cin.clear();
			std::cout << "Error: Empty string. Please try again." << std::endl;
		}
		else
		{
			for(int o = 0; buffer.data()[o]; o++)
			{
				if ((buffer.data()[o] >= '0' && buffer.data()[o] <= '9')
					|| (buffer.data()[o] >= 'a' && buffer.data()[o] <= 'z')
					|| (buffer.data()[o] >= 'A' && buffer.data()[o] <= 'Z')
					|| (buffer.data()[o] >= ' '))
					continue ;
				else
				{
					spec = 1;
					buffer.replace(o, sizeof(char), "?");
				}
			}
			is_waitting = 0;
		}
	}
	if (spec)
		std::cout << "Special character(s) was found and be replaced by ?" << std::endl;
	return (buffer);
}


Contact::~Contact(void)
{
	for (int i = 0; i < i_max; i++)
		this->info[i] = "";
	this->_index = 0;
}
