/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:11:24 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/03 15:47:22 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0), _span() {}

Span::Span(unsigned int N) : _N(N), _span() {}

Span::Span(Span const &other) : _N(other._N), _span(other._span) {}

Span	&Span::operator=(Span const &other) {
	if (this != &other) {
		_N = other._N;
		_span = other._span;
	}
	return (*this);
}

void	Span::addNumber(int number) {
	if (_N == 0)
		throw (std::runtime_error("Span has max capacity of 0, cannot store any numbers."));
	else if (_span.size() < _N)
		_span.push_back(number);
	else
		throw (std::runtime_error("Span is full, cannot add more numbers."));
}

int	Span::shortestSpan() {
	if (_span.empty() || _span.size() == 1)
		throw (std::runtime_error("Span needs at least 2 elements to compute shortest span."));
	std::sort(_span.begin(), _span.end());
	int	shortest = INT_MAX;
	for (size_t i = 1; i < _span.size(); i++) {
		if (_span[i] - _span[i - 1] < shortest)
			shortest = _span[i] - _span[i - 1];
	}
	return (shortest);
}

int	Span::longestSpan() {
	if (_span.empty() || _span.size() == 1)
		throw (std::runtime_error("Span needs at least 2 elements to compute longest span."));
	std::sort(_span.begin(), _span.end());
	return (_span.back() - _span[0]);
}

Span::~Span() {}
