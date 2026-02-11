/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:35:24 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/11 18:17:45 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== TEST 1: Basic Polymorphism ===" << std::endl;
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << "Type of j: " << j->getType() << std::endl;
		std::cout << "Type of i: " << i->getType() << std::endl;
		std::cout << "Type of meta: " << meta->getType() << std::endl;

		std::cout << "\nMaking sounds:" << std::endl;
		i->makeSound();	   // Cat sound
		j->makeSound();	   // Dog sound
		meta->makeSound(); // Generic animal sound

		std::cout << "\nDeleting animals..." << std::endl;
		delete i;
		delete j;
		delete meta;
	}

	std::cout << "\n=== TEST 2: WrongAnimal Class ===" << std::endl;
	{
		const WrongAnimal *wrong = new WrongAnimal();
		const WrongAnimal *wrongCat = new WrongCat();

		std::cout << "Type of wrong: " << wrong->getType() << std::endl;
		std::cout << "Type of wrongCat: " << wrongCat->getType() << std::endl;

		std::cout << "\nMaking sounds (without virtual):" << std::endl;
		wrong->makeSound();	   // WrongAnimal sound
		wrongCat->makeSound(); // Still WrongAnimal sound! (no polymorphism)

		std::cout << "\nDeleting wrong animals..." << std::endl;
		delete wrong;
		delete wrongCat; // Might not call WrongCat destructor properly!
	}

	std::cout << "\n=== TEST 3: Array of Animals ===" << std::endl;
	{
		const Animal *animals[4];

		animals[0] = new Dog();
		animals[1] = new Cat();
		animals[2] = new Dog();
		animals[3] = new Cat();

		std::cout << "\nAll animals making sounds:" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
			animals[i]->makeSound();
		}

		std::cout << "\nDeleting all animals..." << std::endl;
		for (int i = 0; i < 4; i++)
			delete animals[i];
	}

	std::cout << "\n=== TEST 4: Copy Constructor Test ===" << std::endl;
	{
		Dog originalDog;
		originalDog.makeSound();

		Dog copiedDog(originalDog);
		copiedDog.makeSound();

		Cat originalCat;
		Cat copiedCat = originalCat;
		copiedCat.makeSound();
	}

	std::cout << "\n=== TEST 5: Assignment Operator Test ===" << std::endl;
	{
		Dog dog1;
		Dog dog2;

		dog2 = dog1;
		dog2.makeSound();

		Cat cat1;
		Cat cat2;
		cat2 = cat1;
		cat2.makeSound();
	}

	std::cout << "\n=== TEST 6: Stack vs Heap Allocation ===" << std::endl;
	{
		std::cout << "Stack allocation:" << std::endl;
		Animal stackAnimal;
		Dog stackDog;
		Cat stackCat;

		stackAnimal.makeSound();
		stackDog.makeSound();
		stackCat.makeSound();

		std::cout << "\nHeap allocation:" << std::endl;
		Animal *heapAnimal = new Animal();
		Dog *heapDog = new Dog();
		Cat *heapCat = new Cat();

		heapAnimal->makeSound();
		heapDog->makeSound();
		heapCat->makeSound();

		delete heapAnimal;
		delete heapDog;
		delete heapCat;
	} // Stack objects destroyed here automatically

	return 0;
}