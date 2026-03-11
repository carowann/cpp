/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:55:07 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/10 17:37:35 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ------------------------------------ OCF ----------------------------------- */

RPN::RPN() : _stack() {}

RPN::RPN(RPN const &other) : _stack(other._stack) {}

RPN	&RPN::operator=(RPN const &other) {
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN() {}

/* -------------------------------------------------------------------------- */

void	RPN::solveExpression(std::string const &expr) {
	for (size_t i = 0; i < expr.size(); i++) {
		if (std::isspace(expr[i]))
			continue ;
		if (std::isdigit(expr[i]))
			_stack.push((expr[i]) - '0');
		else if (strchr("+-/*", expr[i])) {
			if (_stack.size() < 2)
				throw (std::runtime_error("Error"));
			int second = _stack.top();
			_stack.pop();
			int first = _stack.top();
			_stack.pop();
			_stack.push(doOperation(first, expr[i], second));
		}
		else
			throw (std::runtime_error("Error"));
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		throw (std::runtime_error("Error"));
}

int	RPN::doOperation(int const first, char const op, int const second) {
	switch (op) {
		case '+':
			return (first + second);
		case '-':
			return (first - second);
		case '*':
			return (first * second);
		case '/':
			if (second == 0)
				throw (std::runtime_error("Error"));
			return (first / second);
		default:
			throw (std::runtime_error("Error"));
	}
}
