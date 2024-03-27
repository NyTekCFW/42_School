/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:25:36 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/26 03:44:30 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	Contact
{
public:
	Contact(void);
	void	add_contact(int i);
	void	rm_contact(void);
	char	*getfirstname(void);
	char	*getlastname(void);
	char	*getnickname(void);
	char	*getphonenumber(void);
	char	*getsecret(void);
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
	char	_phonenumber[11];
	char	_secret[64];
	int		_index;
	
};