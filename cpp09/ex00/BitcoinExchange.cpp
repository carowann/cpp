/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:39:11 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/09 19:01:45 by cwannhed         ###   ########.fr       */
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
		float	value = strtof(line.substr(sepPos + 1, line.size()).c_str(), NULL);
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

void	BitcoinExchange::validateInputFile(std::string const &filename) {
	std::ifstream inFile;
	inFile.open((filename).c_str());
	if (!inFile.is_open())
		throw (std::runtime_error("Could not open file: " + filename));
	std::string	line;
	std::getline(inFile, line);
	while (std::getline(inFile, line)) {
		size_t sepPos = line.find('|');
		if (sepPos == std::string::npos)
			continue ;
		std::string date = line.substr(0, sepPos);
		if (!validateDate(date)) {
			std::cerr << RED << "Error: bad input => " << date << RESET << std::endl;
			continue ;
		}
		std::string	value = line.substr(sepPos + 1, line.size());
		if (!validateValue(value, true)) {
			std::cerr << RED << "Error: invalid value " << value << RESET << std::endl;
			continue;
		}
		std::map<std::string, float>::iterator it = _exchangeRate.upper_bound(date);
		if (it == _exchangeRate.begin()) {
			std::cerr << RED << "Error: date out of range " << RESET << std::endl;
			continue;
		}
		--it;
		float bc = strtof(value.c_str(), NULL);
		std::cout << GREEN << date << " => " << value << " = " << bc * it->second << RESET << std::endl;
	}
}

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

bool	BitcoinExchange::validateValue(std::string const &value, bool isInput) {
	char* pEnd;
	float	val = strtof(value.c_str(), &pEnd);
	if (pEnd == value.c_str())
		return (false);
	if (val == HUGE_VALF || val < 0)
		return (false);
	if (isInput && val > 1000)
		return (false);
	return (true);
}

