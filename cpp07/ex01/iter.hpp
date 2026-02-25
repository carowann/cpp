/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:59:22 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/25 14:50:31 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>

# define BOLD	"\033[1m"
# define RESET	"\033[0m"

template <typename T, typename F>
void	iter(T *array, size_t const len, F func) {
	for (size_t i = 0; i < len; i ++)
		func(array[i]);
}

template <typename T, typename F>
void iter(T const *array, size_t const len, F func) {
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}


#endif