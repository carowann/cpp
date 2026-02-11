/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:37:20 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/11 18:19:49 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ------------------------------------ OCF ----------------------------------- */

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(Cat const &other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat	&Cat::operator=(Cat const &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void	Cat::makeSound() const {
	std::cout << "Miao!" << std::endl;
}
