/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:49:44 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/11 18:00:36 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAAnimal.hpp"
#include "AAnimal.hpp"

/* ------------------------------------ OCF ----------------------------------- */

WrongAAnimal::WrongAAnimal() : type("") {
	std::cout << "WrongAAnimal default constructor called" << std::endl;
}

WrongAAnimal::WrongAAnimal(WrongAAnimal const &other) {
	std::cout << "WrongAAnimal copy constructor called" << std::endl;
	type = other.type;
}

WrongAAnimal &WrongAAnimal::operator=(WrongAAnimal const &other) {
	std::cout << "WrongAAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

WrongAAnimal::~WrongAAnimal() {
	std::cout << "WrongAAnimal destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

std::string WrongAAnimal::getType(void) const {
	return (type);
}

/* -------------------------------------------------------------------------- */

void	WrongAAnimal::makeSound() const {
	std::cout << "Wrong boink!" << std::endl;
}
