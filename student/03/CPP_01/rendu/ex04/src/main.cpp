/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 04:26:50 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 17:49:13 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exercice.hpp"

static void	replace(std::string& filename, std::string& s1, std::string& s2)
{
	std::string output_file_name = filename + ".replace";
	std::string line = "";
	size_t	pos = 0;

	std::ifstream open_file(filename.c_str(), std::ios::out);
	if (!open_file)
	{
		std::cerr << "Error: Failed to open: " << filename.c_str() << std::endl;
		return ;
	}
	std::ofstream output_file(output_file_name.c_str(), std::ios::binary);
	if (!output_file)
	{
		std::cerr << "Error: Failed to create: " << output_file_name.c_str() << std::endl;
		return ;
	}
	while (std::getline(open_file, line))
	{
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			output_file << line.substr(0, pos);
			output_file << s2;
			line = line.substr(pos + s1.length());
			pos = 0;
		}
		output_file << line;
		output_file << '\n';
	}
	output_file.close();
	open_file.close();
	std::cout << "Every " << s1 << " occurrence replaced by " << s2 << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	replace(filename, s1, s2);
	return (0);
}
