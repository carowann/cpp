/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:57:55 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/11 13:05:29 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "=== Creating ClapTrap ===" << std::endl;
	ClapTrap clap("Clappy");

	std::cout << "\n=== Creating ScavTrap ===" << std::endl;
	ScavTrap scav("Scavvy");

	std::cout << "\n=== Creating FragTrap ===" << std::endl;
	FragTrap frag("Fraggy");

	std::cout << "\n=== Testing attacks ===" << std::endl;
	clap.attack("enemy1");
	scav.attack("enemy2");
	frag.attack("enemy3");

	std::cout << "\n=== Testing special abilities ===" << std::endl;
	scav.guardGate();
	frag.highFivesGuys();

	std::cout << "\n=== Testing FragTrap damage & repair ===" << std::endl;
	frag.takeDamage(40);
	frag.beRepaired(30);
	frag.attack("enemy4");

	std::cout << "\n=== Testing copy ===" << std::endl;
	FragTrap frag2(frag);
	frag2.highFivesGuys();

	std::cout << "\n=== Destructors ===" << std::endl;
	return 0;
}
