/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:15:19 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/05 18:12:51 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int			N;
	std::string	zombieName;
	Zombie		*zombie;

	std::cout << BLUE "First horde of 5 Zombino zombies" RESET << std::endl;
	N = 5;
	zombieName = "Zombino";
	zombie = Zombie::zombieHorde(N, zombieName);
	if (!zombie)
		std::cout << RED "Error while allocating first zombie horde!" RESET << std::endl;
	else
	{
		for (int i = 0; i < N ; i++)
			zombie[i].announce();
		delete[] zombie;
	}

	std::cout << BLUE "Second horde with one lonely Pinolo zombie" RESET << std::endl;
	N = 1;
	zombieName = "Pinolo";
	zombie = Zombie::zombieHorde(N, zombieName);
	if (!zombie)
		std::cout << RED "Error while allocating second zombie horde!" RESET << std::endl;
	else
	{
		for (int i = 0; i < N ; i++)
			zombie[i].announce();
		delete[] zombie;
	}

	std::cout << BLUE "Third horde to check error management with N < 1 zombies" RESET << std::endl;
	N = -3;
	zombieName = "Castagna";
	zombie = Zombie::zombieHorde(N, zombieName);
	if (!zombie)
		std::cout << RED "Error while allocating second zombie horde!" RESET << std::endl;
	else
	{
		for (int i = 0; i < N ; i++)
			zombie[i].announce();
		delete[] zombie;
	}

	std::cout << BLUE "Fourth horde to check error management with nameless zombies" RESET << std::endl;
	N = 3;
	zombieName = "";
	zombie = Zombie::zombieHorde(N, zombieName);
	if (!zombie)
		std::cout << RED "Error while allocating second zombie horde!" RESET << std::endl;
	else
	{
		for (int i = 0; i < N ; i++)
			zombie[i].announce();
		delete[] zombie;
	}
	return (0);
}
