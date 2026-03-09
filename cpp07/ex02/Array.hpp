/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:37:21 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/09 14:41:54 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>
# include <cstdlib>
# include <string>

# define BOLD	"\033[1m"
# define RESET	"\033[0m"

template <typename T>
class Array {
private:
	T				*_data;
	unsigned int	_size;
public:
	Array();
	Array(Array const &other);
	Array(unsigned int n);

	Array			&operator=(Array const &other);
	T				&operator[](unsigned int idx);
	unsigned int	size() const;

	~Array();
};

# include "Array.tpp"

#endif