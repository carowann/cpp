/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:59:06 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/11 12:24:33 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ------------------------------------ OCF ----------------------------------- */

ScavTrap::ScavTrap() : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap parametric constructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void ScavTrap::attack(std::string const &target)
{
	if (target.empty()) {
		std::cout << BLUE << "ScavTrap " << this->_name << " found inner peace and doesn't attack anyone!" << RESET << std::endl;
		return;
	}
	if (this->_hitPoints == 0) {
		std::cout << BLUE << "ScavTrap " << this->_name << " can't attack " << target
				<< ": no hit points!" << RESET << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << BLUE << "ScavTrap " << this->_name << " can't attack " << target
				<< ": no energy points!" << RESET << std::endl;
		return;
	}
	std::cout << BLUE << "ScavTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
	this->_energyPoints--;
}

void	ScavTrap::guardGate() {
	std::cout << BOLD << "ScavTrap " << this->_name << " is now in Gate keeper mode" << RESET << std::endl;
}