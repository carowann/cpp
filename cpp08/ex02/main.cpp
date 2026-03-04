/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:33:20 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/04 12:54:18 by cwannhed         ###   ########.fr       */
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

int main() {
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
	MutantStack<int>::iterator itMStack = mstack.begin();
	MutantStack<int>::iterator iteMStack = mstack.end();
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

	if (mstack_out == list_out)
		std::cout << GREEN << BOLD << "\n[OK] MutantStack and list outputs match!" << RESET << std::endl;
	else
		std::cout << RED << BOLD << "\n[KO] Outputs differ!" << RESET << std::endl;

	/* -------------------------------------------------------------------------- */
	testHeader("Test 1: reverse iterators");
	MutantStack<int>::reverse_iterator	rItMStack = mstack.rbegin();
	MutantStack<int>::reverse_iterator	rIteMStack = mstack.rend();
	while (rItMStack != rIteMStack) {
		mstack_out.push_back(*rItMStack);
		std::cout << *rItMStack << " ";
		++rItMStack;
	}
	/* -------------------------------------------------------------------------- */
	testHeader("Test 2 : const iterators");
	MutantStack<int>::const_iterator			cItMStack = mstack.begin();
	MutantStack<int>::const_iterator			cIteMStack = mstack.end();
	MutantStack<int>::const_reverse_iterator	crItMStack = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator	crIteMStack = mstack.rend();

	while (cItMStack != cIteMStack) {
		mstack_out.push_back(*cItMStack);
		std::cout << *cItMStack << " ";
		++cItMStack;
	}
	std::cout << std::endl;
	while (crItMStack != crIteMStack) {
		mstack_out.push_back(*crItMStack);
		std::cout << *crItMStack << " ";
		++crItMStack;
	}
	/* -------------------------------------------------------------------------- */
	testHeader("Test 3: MutantStack w/ string");
	MutantStack<std::string>	mstackStr;
	mstackStr.push("we");
	mstackStr.push("ciao");
	mstackStr.push("pippo");
	mstackStr.push("!!!");
	MutantStack<std::string>::iterator itMStackStr = mstackStr.begin();
	MutantStack<std::string>::iterator iteMStackStr = mstackStr.end();
	while (itMStackStr != iteMStackStr) {
		std::cout << *itMStackStr << " ";
		++itMStackStr;
	}

	return (0);
}