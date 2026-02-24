/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:59:22 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/24 18:25:03 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>

template <typename T, typename F>
void	iter(T *array, size_t const len, F func) {
	for (size_t i = 0; i < len; i ++)
		func(array[i]);
}

template <typename T>
void	print(T const &a) {
	std::cout << a << std::endl;
}

#endif