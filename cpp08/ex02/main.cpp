/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:33:20 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/04 13:55:43 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>
#include <iostream>
#include <string>

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define BOLD	"\033[1m"
#define RESET	"\033[0m"

void	testHeader(std::string const &testName) {
	std::cout << BOLD << "\n==================== " << testName << " ====================" << RESET << std::endl;
}

void	printResult(bool ok) {
	if (ok)
		std::cout << GREEN << BOLD << "[OK]" << RESET << std::endl;
	else
		std::cout << RED << BOLD << "[KO]" << RESET << std::endl;
}

int main() {

	/* ---------------------------------------------------------------------- */
	testHeader("Test 0: subject example - MutantStack vs std::list");

	std::vector<int>	mstack_out;
	std::vector<int>	list_out;
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "[MutantStack] top:  " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "[MutantStack] size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	itMStack = mstack.begin();
	MutantStack<int>::iterator	iteMStack = mstack.end();
	++itMStack;
	--itMStack;
	std::cout << "[MutantStack] elements: ";
	while (itMStack != iteMStack) {
		mstack_out.push_back(*itMStack);
		std::cout << *itMStack << " ";
		++itMStack;
	}
	std::cout << std::endl;

	std::list<int>	lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "[list]        top:  " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "[list]        size: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator	itList = lst.begin();
	std::list<int>::iterator	iteList = lst.end();
	++itList;
	--itList;
	std::cout << "[list]        elements: ";
	while (itList != iteList) {
		list_out.push_back(*itList);
		std::cout << *itList << " ";
		++itList;
	}
	std::cout << std::endl;

	std::cout << "MutantStack == list: ";
	printResult(mstack_out == list_out);

	/* ---------------------------------------------------------------------- */
	testHeader("Test 1: reverse iterators");

	MutantStack<int>::reverse_iterator	rItMStack = mstack.rbegin();
	MutantStack<int>::reverse_iterator	rIteMStack = mstack.rend();
	std::cout << "reverse elements: ";
	while (rItMStack != rIteMStack) {
		std::cout << *rItMStack << " ";
		++rItMStack;
	}
	std::cout << std::endl;

	/* ---------------------------------------------------------------------- */
	testHeader("Test 2: const iterators");

	const MutantStack<int>						cmstack(mstack);
	MutantStack<int>::const_iterator			cIt = cmstack.begin();
	MutantStack<int>::const_iterator			cIte = cmstack.end();
	MutantStack<int>::const_reverse_iterator	crIt = cmstack.rbegin();
	MutantStack<int>::const_reverse_iterator	crIte = cmstack.rend();

	std::cout << "const forward:  ";
	while (cIt != cIte) {
		std::cout << *cIt << " ";
		++cIt;
	}
	std::cout << std::endl;

	std::cout << "const reverse:  ";
	while (crIt != crIte) {
		std::cout << *crIt << " ";
		++crIt;
	}
	std::cout << std::endl;

	/* ---------------------------------------------------------------------- */
	testHeader("Test 3: copy constructor");

	MutantStack<int>	mstackCopy(mstack);
	std::vector<int>	orig_out;
	std::vector<int>	copy_out;

	MutantStack<int>::iterator itOrig = mstack.begin();
	MutantStack<int>::iterator iteOrig = mstack.end();
	while (itOrig != iteOrig) { orig_out.push_back(*itOrig); ++itOrig; }

	MutantStack<int>::iterator itCopy = mstackCopy.begin();
	MutantStack<int>::iterator iteCopy = mstackCopy.end();
	while (itCopy != iteCopy) { copy_out.push_back(*itCopy); ++itCopy; }

	std::cout << "copy == original: ";
	printResult(orig_out == copy_out);

	/* ---------------------------------------------------------------------- */
	testHeader("Test 4: operator=");

	MutantStack<int>	mstackAssigned;
	mstackAssigned.push(999);
	mstackAssigned = mstack;

	std::vector<int>	assigned_out;
	MutantStack<int>::iterator itAssigned = mstackAssigned.begin();
	MutantStack<int>::iterator iteAssigned = mstackAssigned.end();
	while (itAssigned != iteAssigned) { assigned_out.push_back(*itAssigned); ++itAssigned; }

	std::cout << "assigned == original: ";
	printResult(orig_out == assigned_out);

	/* ---------------------------------------------------------------------- */
	testHeader("Test 5: MutantStack<std::string>");

	MutantStack<std::string>	mstackStr;
	mstackStr.push("we");
	mstackStr.push("ciao");
	mstackStr.push("pippo");
	mstackStr.push("!!!");

	MutantStack<std::string>::iterator	itStr = mstackStr.begin();
	MutantStack<std::string>::iterator	iteStr = mstackStr.end();
	std::cout << "string elements: ";
	while (itStr != iteStr) {
		std::cout << *itStr << " ";
		++itStr;
	}
	std::cout << std::endl;

	return (0);
}
