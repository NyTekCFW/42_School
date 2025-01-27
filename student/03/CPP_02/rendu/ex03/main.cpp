/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:42:29 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 18:26:29 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	{
		const Point a;
		const Point b(10, 0);
		const Point c(0, 10);
		const Point point(1, 1);

		std::cout << "point position( x= " << point.get_x() << "\t\ty= " << point.get_y() << "\t)\n" << "\ta( x= " << a.get_x() << "\t\ty= " << a.get_y() << "\t)\n" << "\tb( x= " << b.get_x() << "\ty= " << b.get_y() << "\t)\n" << "\tc( x= " << c.get_x() << "\t\ty= " << c.get_y() << "\t)\n" << std::endl;
		if (bsp(a, b, c, point) == true)
			std::cout << " is inside the triangle" << std::endl;
		else
			std::cout << " is not inside the triangle" << std::endl;
	}
	std::cout << "other test" << std::endl;
	{
		Point a(-1.5, -1.5);
		Point b(2.5, 2.5);
		Point c(-1, -2);
		Point point(8.5, -9);

		std::cout << "The point( x= " << point.get_x() << "\ty= " << point.get_y() << "\t)\n" << "\ta( x= " << a.get_x() << "\ty= " << a.get_y() << "\t)\n" << "\tb( x= " << b.get_x() << "\ty= " << b.get_y() << "\t)\n" << "\tc( x= " << c.get_x() << "\ty= " << c.get_y() << "\t)\n" << std::endl;
		if (bsp(a, b, c, point) == true)
			std::cout << " is inside the triangle" << std::endl;
		else
			std::cout << " is not inside the triangle" << std::endl;
	}
	return (0);
}