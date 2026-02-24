/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:59:12 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/24 18:23:54 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main() {
	int	intArray[10];
	for (size_t i = 0; i < 10; i++) {
		intArray[i] = i;
	}
	iter(intArray, 10, print<int>);
	return (0);

}