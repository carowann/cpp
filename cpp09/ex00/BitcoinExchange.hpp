/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:39:35 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/09 18:33:15 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BITCOINTEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <fstream>
# include <exception>
# include <cstdlib>
# include <iostream>
# include <istream>
# include <cmath>

# define BOLD	"\033[1m"
# define BLUE	"\033[0;34m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define RESET	"\033[0m"

class BitcoinExchange {
private:
	std::map<std::string, float>	_exchangeRate;
	bool	validateDate(const std::string& date);
	bool	validateValue(const std::string& value, bool isInput);
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &other);

	BitcoinExchange	&operator=(BitcoinExchange const &other);

	void	validateInputFile(std::string const &filename);
	~BitcoinExchange();
};

#endif