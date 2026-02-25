/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:40:42 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/25 17:37:01 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP


template <typename T>
void	swap(T &a, T &b) {
	T	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(T const &a, T const &b) {
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T	max(T const &a, T const &b) {
	if (a > b)
		return (a);
	return (b);
}

#endif