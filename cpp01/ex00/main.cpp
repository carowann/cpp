/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:03:35 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/05 16:40:36 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::cout << BLUE "=== Stack allocated zombie ===" RESET << std::endl;
	Zombie	stackZombie("StackZombie");
	stackZombie.announce();

	std::cout << BLUE "\n=== Heap allocated zombie ===" RESET << std::endl;
	Zombie	*heapZombie;
	heapZombie = NULL;
	heapZombie = Zombie::newZombie("HeapZombie");
	heapZombie->announce();
	std::cout << "Deleting HeapZombie ..." << std::endl;
	delete heapZombie;
	heapZombie = NULL;
	std::cout << "Heap zombie is officially dead :(" << std::endl;

	std::cout << BLUE "\n=== The short life of the random zombie ===" RESET << std::endl;
	Zombie::randomChump("Random zombie");
	std::cout << "Random zombie is already dead :(" << std::endl;

	std::cout << "\nStack zombie is still alive :)" << std::endl;
	stackZombie.announce();
	std::cout << "Stack zombie will die with the program :(" << std::endl;
	return (0);
}
