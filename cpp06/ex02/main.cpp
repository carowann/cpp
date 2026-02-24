/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:56:34 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/24 16:39:25 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

int main() {
	srand(time(NULL));
	Base	*abc1 = generate();
	Base	*abc2 = generate();

	identify(abc1);
	identify(*abc1);
	std::cout << "---" << std::endl;
	identify(abc2);
	identify(*abc2);

	delete abc1;
	delete abc2;
}
