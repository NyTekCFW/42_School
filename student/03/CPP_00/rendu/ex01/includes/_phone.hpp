/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _phone.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:02:43 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/27 00:23:02 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _PHONE_HPP
# define _PHONE_HPP

# include <iostream>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>

enum e_type
{
	ADD = 2104842452U,
	SEARCH = 919674409U,
	EXIT = 2038653189U
};

enum e_info
{
	i_firstname	= 0,
	i_lastname,
	i_nickname,
	i_phone,
	i_secret,
	i_max
};

#endif
