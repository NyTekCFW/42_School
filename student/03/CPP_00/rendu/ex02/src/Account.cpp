/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 02:45:05 by lchiva            #+#    #+#             */
/*   Updated: 2024/03/27 05:23:49 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
# include <iostream>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>

Account::Account(void)
{
	this->_displayTimestamp();
}

Account::Account(int initial_deposit)
{

}

Account::~Account(void)
{

}


int	Account::getNbAccounts(void)
{

}

int	Account::getTotalAmount(void)
{

}

int	Account::getNbDeposits(void)
{

}

int	Account::getNbWithdrawals(void)
{

}

void	Account::displayAccountsInfos(void)
{

}

void	Account::makeDeposit( int deposit )
{

}

bool	Account::makeWithdrawal( int withdrawal )
{

}

int	Account::checkAmount( void ) const
{

}

void	Account::displayStatus( void ) const
{

}

void	Account::_displayTimestamp( void )
{
	std::cout << "[" << __TIMESTAMP__ << "] ";
}