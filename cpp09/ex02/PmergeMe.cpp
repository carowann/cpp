/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:38:31 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/19 16:13:27 by cwannhed         ###   ########.fr       */
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

void	PmergeMe::parseArgs(int const argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '\0')
			throw (std::runtime_error("Invalid input"));
		char *endPtr;
		long number = strtol(argv[i], &endPtr, 10);
		if (*endPtr != '\0' || number < 0 || number > INT_MAX)
		throw (std::runtime_error("Invalid input"));
		_toSortVector.push_back(number);
		_toSortDeque.push_back(number);
	}
}

void PmergeMe::sort() {
	timespec	start, end;
	std::cout << "Before : ";
	printVector(_toSortVector);
	clock_gettime(CLOCK_MONOTONIC, &start);
	std::vector<int> sortedVector = sortVector(_toSortVector);
	clock_gettime(CLOCK_MONOTONIC, &end);
	std::cout << "After sorting on a vector: ";
	printVector(sortedVector);
	double elapsed = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1000.0;
	std::cout << "Time to process a range of "<< _toSortVector.size() << " elements with std::vector : " << elapsed << " us" << std::endl;
	clock_gettime(CLOCK_MONOTONIC, &start);
	std::deque<int> sortedDeque = sortDeque(_toSortDeque);
	clock_gettime(CLOCK_MONOTONIC, &end);
	std::cout << "After sorting on a deque: ";
	printDeque(sortedDeque);
	elapsed = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1000.0;
	std::cout << "Time to process a range of "<< _toSortDeque.size() << " elements with std::deque : " << elapsed << " us" << std::endl;
}

std::vector<int> PmergeMe::jacobsthalSequence(size_t n) {
	std::vector<int> Jacob;
	Jacob.push_back(1);
	Jacob.push_back(3);
	while (true) {
		int JacobNumber = Jacob.back() + 2 * Jacob[Jacob.size() - 2];
		if (JacobNumber >= static_cast<int>(n))
			break;
		Jacob.push_back(JacobNumber);
	}
	return (Jacob);
}

/* ------------------------------------ VECTOR ----------------------------------- */

std::vector<int>	PmergeMe::sortVector(std::vector<int> &v) {
	if (v.size() <= 1)
		return (v);
	std::vector<std::pair<int, int> > pairs = formPairs(v);
	int leftOver = -1;
	if (v.size() % 2 != 0)
		leftOver = v.back();
	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].second);
	mainChain = sortVector(mainChain);
	mainChain = insertPendingNumbers(mainChain, pairs);
	if (leftOver != -1) {
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftOver);
		mainChain.insert(pos, leftOver);
	}
	return (mainChain);
}

std::vector<int> PmergeMe::insertPendingNumbers(std::vector<int> &mainChain, std::vector<std::pair<int, int> > &pairs) {
	std::vector<int> insertionIdxs = findJacobsthalIndexes(pairs);
	for (size_t i = 0; i < insertionIdxs.size(); i++) {
		int pairIdx = insertionIdxs[i] - 1;
		int toInsert = pairs[pairIdx].first;
		int larger = pairs[pairIdx].second;
		std::vector<int>::iterator bound = std::upper_bound(mainChain.begin(), mainChain.end(), larger);
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), bound, toInsert);
		mainChain.insert(pos, toInsert);
	}
	return (mainChain);
}

std::vector<std::pair<int, int> >	PmergeMe::formPairs(std::vector<int> &v) {
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0 ; i < v.size(); i+=2) {
		if (v.size() % 2 != 0 && i == v.size() - 1)
			break;
		int smaller = v[i];
		int larger = v[i + 1];
		if (v[i] > v[i + 1]) {
			larger =  v[i];
			smaller = v[i + 1];
		}
		pairs.push_back(std::make_pair(smaller, larger));
	}
	return (pairs);
}

std::vector<int> PmergeMe::findJacobsthalIndexes(std::vector<std::pair<int, int> > &pairs) {
	std::vector<int> Jacob = jacobsthalSequence(pairs.size());
	std::vector<int> edit;
	edit.push_back(1);
	for (size_t i = 1; i < Jacob.size(); i++) {
		int x = Jacob[i];
		while (x > Jacob[i - 1]) {
			if (x <= (int)pairs.size())
				edit.push_back(x);
			x--;
		}
	}
	for (int i = (int)pairs.size(); i > Jacob.back(); i--)
		edit.push_back(i);
	return (edit);
}

void PmergeMe::printVector(std::vector<int> &v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
}

/* ------------------------------------ DEQUE ----------------------------------- */

std::deque<int>	PmergeMe::sortDeque(std::deque<int> &d) {
	if (d.size() <= 1)
		return (d);
	std::deque<std::pair<int, int> > pairs = formPairs(d);
	int leftOver = -1;
	if (d.size() % 2 != 0)
		leftOver = d.back();
	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].second);
	mainChain = sortDeque(mainChain);
	mainChain = insertPendingNumbers(mainChain, pairs);
	if (leftOver != -1) {
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftOver);
		mainChain.insert(pos, leftOver);
	}
	return (mainChain);
}

std::deque<int>	PmergeMe::insertPendingNumbers(std::deque<int> &mainChain, std::deque<std::pair<int,int> > &pairs) {
	std::deque<int> insertionIdxs = findJacobsthalIndexes(pairs);
	for (size_t i = 0; i < insertionIdxs.size(); i++) {
		int pairIdx = insertionIdxs[i] - 1;
		int toInsert = pairs[pairIdx].first;
		std::deque<int>::iterator bound = std::upper_bound(mainChain.begin(), mainChain.end(), pairs[pairIdx].second);
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), bound, toInsert);
		mainChain.insert(pos, toInsert);
	}
	return (mainChain);
}

std::deque<std::pair<int, int> >	PmergeMe::formPairs(std::deque<int> &d) {
		std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0 ; i < d.size(); i+=2) {
		if (d.size() % 2 != 0 && i == d.size() - 1)
			break;
		int smaller = d[i];
		int larger = d[i + 1];
		if (d[i] > d[i + 1]) {
			larger =  d[i];
			smaller = d[i + 1];
		}
		pairs.push_back(std::make_pair(smaller, larger));
	}
	return (pairs);
}

std::deque<int> PmergeMe::findJacobsthalIndexes(std::deque<std::pair<int,int> > &pairs) {
	std::vector<int> Jacob = jacobsthalSequence(pairs.size());
	std::deque<int> edit;
	edit.push_back(1);
	for (size_t i = 1; i < Jacob.size(); i++) {
		int x = Jacob[i];
		while (x > Jacob[i - 1]) {
			if (x <= (int)pairs.size())
				edit.push_back(x);
			x--;
		}
	}
	for (int i = (int)pairs.size(); i > Jacob.back(); i--)
		edit.push_back(i);
	return (edit);
}

void PmergeMe::printDeque(std::deque<int> &d) {
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
}
