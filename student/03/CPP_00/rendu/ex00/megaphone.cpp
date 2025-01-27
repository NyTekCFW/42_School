/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:45:46 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:36:45 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int a = 1; a < argc; a++)
		{
			for (int b = 0; argv[a][b]; b++)
				std::cout << (char)std::toupper(argv[a][b]);
		}
		std::cout << std::endl;
	}
	return (1);
}
