/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:25:36 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/26 01:25:12 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	Contact
{
public:
	Contact(void);
	void	add_contact(int i);
	void	rm_contact(void);
	~Contact(void);
private:
	void	_set_firstname(void);
	void	_set_lastname(void);
	void	_set_nickname(void);
	void	_set_phonenumber(void);
	void	_set_secret(void);
	char	_firstname[32];
	char	_lastname[32];
	char	_nickname[32];
	char	_phonenumber[10];
	char	_secret[64];
	int		_index;
	
};