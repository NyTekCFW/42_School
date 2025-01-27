/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:42:33 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:42:33 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{

}

Point::Point(const float x, const float y):_x(x), _y(y)
{
	
}

Point::Point(const Point &copy): _x(copy.get_x()), _y(copy.get_y())
{

}

Point::~Point(void)
{

}

const Fixed &Point::get_x(void) const
{
    return (this->_x);
}

const Fixed &Point::get_y(void) const
{
    return (this->_y);
}

std::ostream	&operator<<(std::ostream &s, Point const p)
{
	s << "_x = " << p.get_x() << " / _y = " << p.get_y() << std::endl;
	return (s);
}