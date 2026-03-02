/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:16:10 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/02 17:56:37 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

void	testHeader(std::string const &testName) {
	std::cout << BOLD << "\n==================== " << testName << " ====================" << RESET << std::endl;
}

int	main() {
	try {
		testHeader("Test 1: Vector [6, 9, 1]");
		std::vector<int>	v;
		v.push_back(6);
		v.push_back(9);
		v.push_back(1);
		std::cout << "Searching for 6 (first)... found: " << *easyfind(v, 6) << std::endl;
		std::cout << "Searching for 1 (last)...  found: " << *easyfind(v, 1) << std::endl;
		std::cout << "Searching for 9 (middle)... found: " << *easyfind(v, 9) << std::endl;
		std::cout << "Searching for 3 (missing)... ";
		std::cout << *easyfind(v, 3) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		testHeader("Test 2: Deque [13, 42, 0]");
		std::deque<int> d;
		d.push_back(0);
		d.push_front(42);
		d.push_front(13);
		std::cout << "Searching for 42... found: " << *easyfind(d, 42) << std::endl;
		std::cout << "Searching for 3 (missing)... ";
		std::cout << *easyfind(d, 3) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		testHeader("Test 3: List [13, 42, 0]");
		std::list<int> l;
		l.push_back(0);
		l.push_front(42);
		l.push_front(13);
		std::cout << "Searching for 42... found: " << *easyfind(l, 42) << std::endl;
		std::cout << "Searching for 3 (missing)... ";
		std::cout << *easyfind(l, 3) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		testHeader("Test 4: Empty container");
		std::deque<int> d;
		std::cout << "Searching for 42 (empty)... ";
		std::cout << *easyfind(d, 42) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}