/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:25:36 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:36:55 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact
{
public:
	Contact(void);
	void		add_contact(int i);
	void		rm_contact(void);
	std::string	get_data(int id);
	std::string	set_data(const char *text);
	~Contact(void);
private:
	std::string	info[i_max];
	int		_index;
	
};
#endif
