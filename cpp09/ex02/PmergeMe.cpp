/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:38:31 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/11 13:57:55 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ------------------------------------ OCF ----------------------------------- */

PmergeMe::PmergeMe() : _toSortVector(), _toSortDeque() {}

PmergeMe::PmergeMe(PmergeMe const &other) : _toSortVector(other._toSortVector), _toSortDeque(other._toSortDeque) {}

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
	if (this != &other) {
		_toSortVector = other._toSortVector;
		_toSortDeque = other._toSortDeque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

/* -------------------------------------------------------------------------- */

void	PmergeMe::parseArgs(int const argc, const char *argv[]) {
	for (int i = 1; i < argc; i++) {
		char *endPtr;
		long number = strtol(argv[i], &endPtr, 10);
		if (*endPtr != '\0' || number < 0 || number > INT_MAX)
			throw (std::runtime_error("Invalid input"));
		_toSortVector.push_back(number);
		_toSortDeque.push_back(number);
	}
}

/* -------------------------------------------------------------------------- */
