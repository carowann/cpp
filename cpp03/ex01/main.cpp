/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:57:55 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/10 16:04:18 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "\n========== TEST 1: Costruttori e OCF ==========" << std::endl;
	{
		ClapTrap default_clap;
		ClapTrap named_clap("Bob");
		ClapTrap copy_clap(named_clap);
		ClapTrap assigned_clap;
		assigned_clap = named_clap;
	}

	std::cout << "\n========== TEST 2: Attacco Base ==========" << std::endl;
	{
		ClapTrap bob("Bob");
		bob.attack("Enemy");
		bob.attack("Monster");
	}

	std::cout << "\n========== TEST 3: Riparazione Base ==========" << std::endl;
	{
		ClapTrap alice("Alice");
		alice.beRepaired(5);
		alice.beRepaired(3);
	}

	std::cout << "\n========== TEST 4: Prendere Danno ==========" << std::endl;
	{
		ClapTrap charlie("Charlie");
		charlie.takeDamage(3);
		charlie.takeDamage(5);
		charlie.takeDamage(0);
	}

	std::cout << "\n========== TEST 5: Danno Maggiore degli HP ==========" << std::endl;
	{
		ClapTrap dave("Dave");
		dave.takeDamage(15);
		dave.attack("Enemy");
	}

	std::cout << "\n========== TEST 6: Riparazione con HP a Zero ==========" << std::endl;
	{
		ClapTrap eve("Eve");
		eve.takeDamage(10);
		eve.beRepaired(5);
		eve.attack("Enemy");
	}

	std::cout << "\n========== TEST 7: Esaurimento Energy Points ==========" << std::endl;
	{
		ClapTrap frank("Frank");
		for (int i = 0; i < 12; i++)
		{
			std::cout << "\n--- Azione " << i + 1 << " ---" << std::endl;
			if (i % 2 == 0)
				frank.attack("Target");
			else
				frank.beRepaired(2);
		}
	}

	std::cout << "\n========== TEST 8: Attacco con Target Vuoto ==========" << std::endl;
	{
		ClapTrap zen("Zen");
		zen.attack("");
	}

	std::cout << "\n========== TEST 9: Scenario Completo ==========" << std::endl;
	{
		ClapTrap hero("Hero");

		hero.attack("Goblin");
		hero.takeDamage(3);
		hero.beRepaired(2);
		hero.attack("Orc");
		hero.takeDamage(8);
		hero.beRepaired(5);
		hero.attack("Dragon");
	}

	std::cout << "\n========== Fine Test ==========" << std::endl;
	return (0);
}