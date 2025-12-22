/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:05:56 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/22 11:53:15 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(), _amount(), _nbDeposits(), _nbWithdrawals()
{
	_amount = initial_deposit;
	_accountIndex = getNbAccounts();
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created" << std::endl;
	_nbAccounts++;
	_totalAmount += _amount;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
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

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";deposit:" << deposit;
	if (deposit > 0)
	{
		_amount += deposit;
		_nbDeposits++;
		_totalNbDeposits++;
		_totalAmount += deposit;
	}
	std::cout << ";amount:" <<_amount
			<< ";nb_deposits:" << _nbDeposits
			<< std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
			<< ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals
			<< std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals
			<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	amount;

	amount = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << _amount;
	amount = checkAmount();
	if (withdrawal < 0 || amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
		return (true);
	}
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

