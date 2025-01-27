/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:41:40 by lchiva            #+#    #+#             */
/*   Updated: 2024/09/06 07:41:40 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
		Fixed(void);
		~Fixed(void);
		Fixed(int const v);
		Fixed(float const v);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		Fixed(Fixed const &copy);
		static Fixed	&min(Fixed &first, Fixed &second);
		static const Fixed	&min(const Fixed &first, const Fixed &second);
		static Fixed	&max(Fixed &first, Fixed &second);
		static const Fixed	&max(const Fixed &first, const Fixed &second);
		//operator
		Fixed	&operator=(const Fixed &copy);
		Fixed	operator+(const Fixed &copy) const;
		Fixed	operator-(const Fixed &copy) const;
		Fixed	operator/(const Fixed &copy) const;
		Fixed	operator*(const Fixed &copy) const;
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
		bool 	operator<=(const Fixed &copy) const;
		bool 	operator<(const Fixed &copy) const;
		bool	operator>(const Fixed &copy) const;
		bool	operator>=(const Fixed &copy) const;
		bool	operator==(const Fixed &copy) const;
		bool	operator!=(const Fixed &copy) const;
	private:
		int					_value;
		static const int	_frac;
};

std::ostream &operator<<(std::ostream &str, Fixed const &final_nbr);

#endif