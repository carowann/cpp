/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:35:24 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/13 15:28:53 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << BOLD << "=== TEST 1: Basic Polymorphism ===" << RESET << std::endl;
	{
		const Animal	*meta = new Animal();
		const Animal	*j = new Dog();
		const Animal	*i = new Cat();

		std::cout << "Type of j: " << j->getType() << std::endl;
		std::cout << "Type of i: " << i->getType() << std::endl;
		std::cout << "Type of meta: " << meta->getType() << std::endl;

		std::cout << "\nMaking sounds:" << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		std::cout << RED << "\nDeleting animals..." << RESET << std::endl;
		delete i;
		delete j;
		delete meta;
	}

	std::cout << BOLD << "\n=== TEST 2: WrongAnimal Class ===" << RESET << std::endl;
	{
		const WrongAnimal	*wrong = new WrongAnimal();
		const WrongAnimal	*wrongCat = new WrongCat();

		std::cout << "\nMaking sounds (without virtual):" << std::endl;
		wrong->makeSound();
		wrongCat->makeSound();

		std::cout << RED << "\nDeleting wrong animals..." << RESET << std::endl;
		delete wrong;
		delete wrongCat;
	}

	std::cout << BOLD << "\n=== TEST 3: Copy Constructor Test ===" << RESET << std::endl;
	{
		Dog	originalDog;
		originalDog.makeSound();

		Dog	copiedDog(originalDog);
		copiedDog.makeSound();

		Cat	originalCat;
		Cat	copiedCat = originalCat;
		copiedCat.makeSound();
	}

	std::cout << BOLD << "\n=== TEST 4: Assignment Operator Test ===" << RESET << std::endl;
	{
		Dog	dog1;
		Dog	dog2;

		dog2 = dog1;
		dog2.makeSound();

		Cat	cat1;
		Cat	cat2;
		cat2 = cat1;
		cat2.makeSound();
	}
	return (0);
}