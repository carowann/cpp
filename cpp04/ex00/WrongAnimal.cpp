/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:49:44 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/11 18:00:36 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Animal.hpp"

/* ------------------------------------ OCF ----------------------------------- */

WrongAnimal::WrongAnimal() : type("") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	type = other.type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

std::string WrongAnimal::getType(void) const {
	return (type);
}

/* -------------------------------------------------------------------------- */

void	WrongAnimal::makeSound() const {
	std::cout << "Wrong boink!" << std::endl;
}
