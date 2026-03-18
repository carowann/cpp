/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:37:54 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/18 17:19:33 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <climits>
# include <algorithm>
# include <sys/time.h>

# define BOLD	"\033[1m"
# define BLUE	"\033[0;34m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define RESET	"\033[0m"

class PmergeMe {
private:
	std::vector<int>	_toSortVector;
	std::deque<int>		_toSortDeque;

	//vector
	std::vector<std::pair<int, int> >	formPairs(std::vector<int> &v);
	std::vector<int>					insertPendingNumbers(std::vector<int> &mainChain, std::vector<std::pair<int,int> > &pairs);
	std::vector<int>					sortVector(std::vector<int> &v);
	std::vector<int>					findJacobsthalIndexes(std::vector<std::pair<int,int> > &pairs);
	std::vector<int>					jacobsthalSequence(size_t n);
	void								printVector(std::vector<int> &v);
	//deque
	std::deque<std::pair<int, int> >	formPairs(std::deque<int> &d);
	std::deque<int>						insertPendingNumbers(std::deque<int> &mainChain, std::deque<std::pair<int,int> > &pairs);
	std::deque<int>						sortDeque(std::deque<int> &d);
	std::deque<int>						findJacobsthalIndexes(std::deque<std::pair<int,int> > &pairs);
	void								printDeque(std::deque<int> &d);
public:
	PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe &operator=(PmergeMe const &other);
	~PmergeMe();

	void	sort();
	void	parseArgs(int const argc, char *argv[]);
};

#endif