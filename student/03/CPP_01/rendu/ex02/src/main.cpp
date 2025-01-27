/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 05:38:25 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:39:01 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "Memory address String : " << &str << std::endl;
	std::cout << "Memory address StringPTR : " << ptr << std::endl;
	std::cout << "Memory address stringREF : " << &ref << std::endl;
	
	std::cout << "Value String : " << str << std::endl;
	std::cout << "Value StringPTR : " << *ptr << std::endl;
	std::cout << "Value StringREF : " << ref << std::endl;
}
