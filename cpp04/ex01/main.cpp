/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:35:24 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/12 16:26:32 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal	*animalArray[20];

	for (int i = 0; i < 10; i++) {
		if (i < 5)
			animalArray[i] = new Dog();
		else
			animalArray[i] = new Dog(animalArray);
	}

	for (int i = 0; i < 10; i++)
		delete animalArray[i];
	return (0);
}
