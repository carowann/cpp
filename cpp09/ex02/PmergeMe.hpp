/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:37:54 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/13 16:27:55 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <climits>

# define BOLD	"\033[1m"
# define BLUE	"\033[0;34m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define RESET	"\033[0m"

class PmergeMe {
private:
	std::vector<int, int>				_toSortVector;
	std::deque<int>						_toSortDeque;

	std::vector<int> sortVector(std::vector<int> &v);
public:
	PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe &operator=(PmergeMe const &other);
	~PmergeMe();

	void	parseArgs(int const argc, const char *argv[]);
};

#endif