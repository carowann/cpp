/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:15:19 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/11 17:39:35 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ------------------------------------ OCF ----------------------------------- */

Animal::Animal() : type("") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &other) {
	std::cout << "Animal copy constructor called" << std::endl;
	type = other.type;
}

Animal &Animal::operator=(Animal const &other) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

std::string Animal::getType(void) const {
	return (type);
}

/* -------------------------------------------------------------------------- */

void	Animal::makeSound() const {
	std::cout << "Boink!" << std::endl;
}

