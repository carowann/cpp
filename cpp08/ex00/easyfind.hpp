/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:20:37 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/02 17:40:25 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>
# include <stdexcept>
# include <iostream>

# define BOLD	"\033[1m"
# define RESET	"\033[0m"

template <typename T>
typename T::const_iterator	easyfind(T const &container, int value);

# include "easyfind.tpp"

#endif