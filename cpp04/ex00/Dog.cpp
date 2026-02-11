/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:37:25 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/11 17:37:06 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ------------------------------------ OCF ----------------------------------- */

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(Dog const &other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog	&Dog::operator=(Dog const &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void	Dog::makeSound() const {
	std::cout << "Bau!" << std::endl;
}
