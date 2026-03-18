/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:58:21 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/18 14:36:15 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ------------------------------------ OCF ----------------------------------- */

ClapTrap::ClapTrap() :	_name("Default"),
						_hitPoints(10),
						_energyPoints(10),
						_attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other): _name(other._name),
						_hitPoints(other._hitPoints),
						_energyPoints(other._energyPoints),
						_attackDamage(other._attackDamage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap default destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

ClapTrap::ClapTrap(std::string name) : _name(name),
										_hitPoints(10),
										_energyPoints(10),
										_attackDamage(0) {
	std::cout << "ClapTrap parametric constructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void ClapTrap::attack(std::string const &target)
{
	if (target.empty()) {
		std::cout << BLUE << "ClapTrap " << _name << " found inner peace and doesn't attack anyone!" << RESET << std::endl;
		return;
	}
	if (_hitPoints == 0) {
		std::cout << BLUE << "ClapTrap " << _name << " can't attack " << target
				<< ": no hit points!" << RESET << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << BLUE << "ClapTrap " << _name << " can't attack " << target
				<< ": no energy points!" << RESET << std::endl;
		return;
	}
	std::cout << BLUE << "ClapTrap " << _name << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 0) {
		std::cout << RED << "ClapTrap " << _name
					<< " takes no damage: the attack is too weak!"
					<< RESET << std::endl;
		return;
	}
	std::cout << RED << "ClapTrap " << _name << " has taken "
				<< amount << " points of damage!" << std::endl;
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name
					<< " doesn't have any hit points left!"
					<< RESET << std::endl;
	else
		std::cout << "ClapTrap " << _name << " now has "
					<< _hitPoints << " hit points" << RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0) {
		std::cout << GREEN << "ClapTrap " << _name << " can't repair: no hit points!"
				<< RESET << std::endl;
		return ;
	}
	if (_energyPoints == 0) {
		std::cout << GREEN << "ClapTrap " << _name << " can't repair: no energy points!"
				<< RESET << std::endl;
		return ;
	}
	if (amount == 0) {
		std::cout << GREEN << "ClapTrap " << _name << " can't repair: amount is 0!"
					<< RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "ClapTrap " << _name << " repairs for " << amount
				<< " hit points!" << std::endl;
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " now has " << _hitPoints
				<< " hit points" << RESET << std::endl;
}