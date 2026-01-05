/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:02:24 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/05 18:04:41 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	Zombie	*zombies;

	if (N < 1)
	{
		std::cout << RED "Error! Zombies must be at least one." RESET << std::endl;
		return (NULL);
	}
	if (name.empty())
	{
		std::cout << RED "Error! Zombies must have a name." RESET << std::endl;
		return (NULL);
	}
	zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return (zombies);
}