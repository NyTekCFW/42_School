/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:40:29 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 18:04:44 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	get_id(char *av)
{
	int	i = 0;
	std::string	data[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4)
	{
		if (data[i] == av)
			return (i);
		i++;
	}
	return (-1);
}

int main(int ac, char **av)
{
    Harl    guy;

	switch(ac)
	{
		case 2: 
		{
			switch(get_id(av[1]))
			{
				case 0:
				{
					guy.complain("DEBUG");
					guy.complain("INFO");
					guy.complain("WARNING");
					guy.complain("ERROR");
					break;
				}
				case 1:
				{
					guy.complain("INFO");
					guy.complain("WARNING");
					guy.complain("ERROR");
					break;
				}
				case 2:
				{
					guy.complain("WARNING");
					guy.complain("ERROR");
					break ;
				}
				case 3:guy.complain("ERROR"); break;
				default: std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; break;
			}
			break ;
		}
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		}
	}
    return (1);
}