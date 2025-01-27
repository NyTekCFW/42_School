/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:41:37 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 18:20:05 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(void): _value(0)
{
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed::Fixed(int const v): _value(v * (1 << Fixed::_frac))
{
}

Fixed::Fixed(float const v): _value(roundf(v * (1 << Fixed::_frac)))
{
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->_value) / (float)(1 << Fixed::_frac));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_frac);
}

std::ostream	&operator<<(std::ostream &str, Fixed const &final_nbr)
{
	return (str << final_nbr.toFloat());
}

//operator arythmetique
Fixed	&Fixed::operator=(const Fixed &copy)
{
	this->_value = copy.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &copy) const
{
	return (this->toFloat() + copy.toFloat());
}

Fixed	Fixed::operator-(const Fixed &copy) const
{
	return (this->toFloat() - copy.toFloat());
}

Fixed	Fixed::operator/(const Fixed &copy) const
{
	if (copy.toFloat() == 0 || this->toFloat() == 0)
		return (Fixed(0));
	return (this->toFloat() / copy.toFloat());
}

Fixed	Fixed::operator*(const Fixed &copy) const
{
	return (this->toFloat() * copy.toFloat());
}

//operator increment
//++a
Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}
//a++
Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++this->_value;
	return (tmp);
}

//++a
Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}
//a++
Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--this->_value;
	return (tmp);
}

//operator comparaison
bool Fixed::operator<=(const Fixed &copy) const
{
	return (this->toFloat() <= copy.toFloat());
}

bool Fixed::operator<(const Fixed &copy) const
{
	return (this->toFloat() < copy.toFloat());
}

bool Fixed::operator>(const Fixed &copy) const
{
	return (this->toFloat() > copy.toFloat());
}

bool Fixed::operator>=(const Fixed &copy) const
{
	return (this->toFloat() >= copy.toFloat());
}

bool Fixed::operator==(const Fixed &copy) const
{
	return (this->toFloat() == copy.toFloat());
}

bool Fixed::operator!=(const Fixed &copy) const
{
	return (this->toFloat() != copy.toFloat());
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	return (second);
}
