/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:38:31 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/12 18:11:56 by cwannhed         ###   ########.fr       */
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

void	PmergeMe::sortVector(std::vector<int> &v, size_t start, size_t end) {
	if (start ==  end)
		return ;
	for (size_t i = start; i < end; i++) {
		if (v[i] > v[i + 1]) {
			int temp = v[i];
			v[i] = v[i + 1];
			v[i + 1] = temp;
		}
	}
	return (sortVector(v, start++, end));
}
