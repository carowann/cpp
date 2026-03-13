/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:38:31 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/13 16:39:03 by cwannhed         ###   ########.fr       */
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

std::vector<int>	PmergeMe::sortVector(std::vector<int> &v) {
	if (v.size() <= 1)
		return (v);
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0 ; i < v.size(); i+=2) {
		int smaller = v[i];
		int larger = v[i + 1];
		if (v[i] > v[i + 1]) {
			larger =  v[i];
			smaller = v[i + 1];
		}
		pairs.push_back(std::make_pair(smaller, larger));
	}
	int leftOver = -1;
	if (v.size() % 2 != 0)
		leftOver = v.back();
	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].second);
	mainChain = sortVector(mainChain);
	mainChain.insert(mainChain.begin(), pairs[0].first);
}
