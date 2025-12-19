/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:05:56 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/19 18:01:58 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;

Account::Account(int initial_deposit)
	: _accountIndex(), _amount(), _nbDeposits(), _nbWithdrawals()
{
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout << " index:" <<_accountIndex << ";amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
}

Account::~Account()
{
	//distruttore
}

void	Account::_displayTimestamp( void )
{
	time_t	timeStamp;
	char	date[50];
	struct	tm datetime;

	timeStamp = time(NULL);
	datetime = *localtime(&timeStamp);
	strftime(date, 50, "%Y%m%d_%H%M%S", &datetime);
	std::cout << "[" << date << "]";
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

// int	Account::getTotalAmount()
// {
// 	return (_totalAmount);
// }

// int	Account::getNbDeposits()
// {
// 	return (_totalNbDeposits);
// }

// int Account::getNbWithdrawals()
// {
// 	return (_totalNbWithdrawals);
// }

// void	Account::makeDeposit( int deposit )
// {
// 	//prima lo fa e poi stampa
// 	//index
// 	//prec amount
// 	// deposit
// 	//amount
// 	//nb deposit
// }

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " "
	//acccounts
	//total amounts
	//total deposits
	// total with
}

// void	Account::displayStatus( void ) const
// {
// 	//timestamp
// 	//index
// 	//amount
// 	//deposits
// 	//with
// }

// bool	Account::makeWithdrawal( int withdrawal )
// {
// 	//timestamp
// 	//index
// 	//prec amoutn
// 	//with:
// 	//check amount
// 	//i fpovero refused
// 	//else nb with
// }

// int	Account::checkAmount( void ) const
// {
// 	//
// }
