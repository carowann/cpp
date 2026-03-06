/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:39:11 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/06 18:53:44 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ------------------------------------ OCF ----------------------------------- */

BitcoinExchange::BitcoinExchange() : _exchangeRate() {
	std::ifstream inFile("data.csv");
	if (!inFile.is_open())
		throw (std::exception());
	std::string	line;
	std::getline(inFile, line);
	while (std::getline(inFile, line)) {
		size_t sepPos = line.find(',');
		if (sepPos == std::string::npos)
				continue ;
		std::string date = line.substr(0, sepPos);
		float		value = strtof(line.substr(sepPos + 1, line.size()).c_str(), NULL);
		_exchangeRate[date] = value;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) : _exchangeRate(other._exchangeRate) {}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other) {
	if (this != &other)
		_exchangeRate = other._exchangeRate;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

/* -------------------------------------------------------------------------- */

	// void	validateInputFile(std::string const &filename);

bool	BitcoinExchange::validateDate(std::string const &date) {
	if (date.size() != 10)
		return (false);
	if (date[3] != '-' || date[6] != '-')
		return (false);
	long	month = strtol(date.substr(5, 2).c_str(), NULL, 10);
	if (month < 1 || month > 12)
		return (false);
	long	year = strtol(date.substr(0, 4).c_str(), NULL, 10);
	long	day = strtol(date.substr(8, 2).c_str(), NULL, 10);
	bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	if (month == 2 && isLeap && (day < 1 || day > 29))
		return (false);
	else if (month == 2 && !isLeap && (day < 1 || day > 28))
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
		return (false);
	else if (month != 2 && (day < 1 || day > 31))
		return (false);
	return (true);
}



	// bool	validateValue(const std::string& value, bool isInput);

