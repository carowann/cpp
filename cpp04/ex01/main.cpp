/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:35:24 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/13 15:52:50 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	std::cout << "\n" << BLUE << "=== TEST 1: Array of Animals ===" << RESET << std::endl;
	{
		const int	SIZE = 6;
		Animal		*animals[SIZE];

		for (int i = 0; i < SIZE; i++) {
			std::cout << "\n" << GREEN << "Creating animal " << i << ":" << RESET << std::endl;
			if (i < SIZE / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		std::cout << "\n" << BOLD << "Testing makeSound:" << RESET << std::endl;
		for (int i = 0; i < SIZE; i++) {
			std::cout << animals[i]->getType() << ": ";
			animals[i]->makeSound();
		}

		std::cout << "\n" << BOLD << RED << "Deleting all animals:" << RESET << std::endl;
		for (int i = 0; i < SIZE; i++) {
			std::cout << "\nDeleting animal " << i << ":" << std::endl;
			delete animals[i];
		}
	}

	std::cout << "\n" << BLUE << "=== TEST 2: Deep Copy - Copy Constructor ===" << RESET << std::endl;
	{
		std::cout << "\n" << GREEN << "Creating original Dog:" << RESET << std::endl;
		Dog	original;
		original.getBrain()->setIdea(0, "I love bones");
		original.getBrain()->setIdea(1, "Chase the mailman");
		original.getBrain()->setIdea(2, "Bark at cats");

		std::cout << "\n" << GREEN << "Creating copy via copy constructor:" << RESET << std::endl;
		Dog copy(original);

		std::cout << "\n" << BOLD << "Original Brain ideas:" << RESET << std::endl;
		std::cout << "  [0]: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "  [1]: " << original.getBrain()->getIdea(1) << std::endl;
		std::cout << "  [2]: " << original.getBrain()->getIdea(2) << std::endl;

		std::cout << "\n" << BOLD << "Copy Brain ideas (before modification):" << RESET << std::endl;
		std::cout << "  [0]: " << copy.getBrain()->getIdea(0) << std::endl;
		std::cout << "  [1]: " << copy.getBrain()->getIdea(1) << std::endl;
		std::cout << "  [2]: " << copy.getBrain()->getIdea(2) << std::endl;

		std::cout << "\n" << GREEN << "Modifying copy's ideas:" << RESET << std::endl;
		copy.getBrain()->setIdea(0, "I love treats");
		copy.getBrain()->setIdea(1, "Sleep all day");
		copy.getBrain()->setIdea(2, "Play with toys");

		std::cout << "\n" << BOLD << "Original Brain ideas (should be unchanged):" << RESET << std::endl;
		std::cout << "  [0]: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "  [1]: " << original.getBrain()->getIdea(1) << std::endl;
		std::cout << "  [2]: " << original.getBrain()->getIdea(2) << std::endl;

		std::cout << "\n" << BOLD << "Copy Brain ideas (should be different):" << RESET << std::endl;
		std::cout << "  [0]: " << copy.getBrain()->getIdea(0) << std::endl;
		std::cout << "  [1]: " << copy.getBrain()->getIdea(1) << std::endl;
		std::cout << "  [2]: " << copy.getBrain()->getIdea(2) << std::endl;

		std::cout << "\n" << BOLD << "Brain addresses (should be different):" << RESET << std::endl;
		std::cout << "  Original Brain: " << original.getBrain() << std::endl;
		std::cout << "  Copy Brain:     " << copy.getBrain() << std::endl;

		std::cout << "\n" << RED << "Destroying both Dogs:" << RESET << std::endl;
	}

	std::cout << "\n" << BOLD << BLUE << "=== TEST 3: Deep Copy - Assignment Operator ===" << RESET << std::endl;
	{
		std::cout << "\n" << GREEN << "Creating two Dogs:" << RESET << std::endl;
		Dog dog1;
		Dog dog2;

		dog1.getBrain()->setIdea(0, "Dog1 idea");
		dog2.getBrain()->setIdea(0, "Dog2 idea");

		std::cout << "\n" << BOLD << "Before assignment:" << RESET << std::endl;
		std::cout << "  dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "  dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

		std::cout << "\n" << GREEN << "Assigning dog1 to dog2:" << RESET << std::endl;
		dog2 = dog1;

		std::cout << "\n" << BOLD << "After assignment (both should have same ideas):" << RESET << std::endl;
		std::cout << "  dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "  dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

		std::cout << "\n" << GREEN << "Modifying dog2:" << RESET << std::endl;
		dog2.getBrain()->setIdea(0, "Dog2 new idea");

		std::cout << "\n" << BOLD << "After modification (should be different):" << RESET << std::endl;
		std::cout << "  dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "  dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

		std::cout << "\n" << BOLD << "Brain addresses (should be different):" << RESET << std::endl;
		std::cout << "  dog1 Brain: " << dog1.getBrain() << std::endl;
		std::cout << "  dog2 Brain: " << dog2.getBrain() << std::endl;

		std::cout << "\n" << RED << "Destroying both Dogs:" << RESET << std::endl;
	}

	std::cout << "\n" << BOLD << BLUE << "=== TEST 4: Scope Test (tmp destroyed, original survives) ===" << RESET << std::endl;
	{
		std::cout << "\n" << GREEN << "Creating basic Dog:" << RESET << std::endl;
		Dog basic;
		basic.getBrain()->setIdea(0, "Basic idea");

		std::cout << "\n" << GREEN << "Creating tmp in inner scope:" << RESET << std::endl;
		{
			Dog tmp = basic;
			tmp.getBrain()->setIdea(0, "Tmp idea");
			std::cout << "  tmp idea[0]: " << tmp.getBrain()->getIdea(0) << std::endl;
			std::cout << RED << "tmp will be destroyed now..." << RESET << std::endl;
		}

		std::cout << "\n" << BOLD << GREEN << "basic still alive and working!" << RESET << std::endl;
		std::cout << "  basic idea[0]: " << basic.getBrain()->getIdea(0) << std::endl;

		std::cout << "\n" << RED << "Destroying basic:" << RESET << std::endl;
	}

	std::cout << "\n" << BOLD << GREEN << "=== ALL TESTS COMPLETED ===" << RESET << std::endl;

	return 0;
}
