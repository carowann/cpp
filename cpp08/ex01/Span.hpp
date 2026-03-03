/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:10:46 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/03 15:43:58 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <climits>
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <list>

# define BOLD	"\033[1m"
# define RESET	"\033[0m"

class Span {
private:
	unsigned int		_N;
	std::vector<int>	_span;
public:
	Span();
	Span(unsigned int N);
	Span(Span const &other);
	Span &operator=(Span const &other);

	void	addNumber(int number);
	int		shortestSpan();
	int		longestSpan();

	template <typename T>
	void	addRange(T first, T last) {
		if (static_cast<unsigned int>(std::distance(first, last)) > _N - _span.size())
			throw (std::runtime_error("Too many elements to add."));
		_span.insert(_span.end(), first, last);
	}

	~Span();
};

#endif
