/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:15:19 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/11 17:39:35 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* ------------------------------------ OCF ----------------------------------- */

AAnimal::AAnimal() : type("") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &other) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	type = other.type;
}

AAnimal &AAnimal::operator=(AAnimal const &other) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

std::string AAnimal::getType(void) const {
	return (type);
}


