/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:54:37 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/10 17:08:53 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include "iostream"
# include <stack>
# include <cstring>
# include <cctype>
# include <exception>

# define BOLD	"\033[1m"
# define BLUE	"\033[0;34m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define RESET	"\033[0m"

class RPN {
private:
	std::stack<int>	_stack;

	int	doOperation(int first, char op, int second);
public:
	RPN();
	RPN(RPN const &other);
	RPN	&operator=(RPN const &other);
	~RPN();
	void	parseExpression(std::string const &expr);

};

#endif