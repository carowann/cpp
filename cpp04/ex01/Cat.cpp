/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:37:20 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/13 12:36:19 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ------------------------------------ OCF ----------------------------------- */

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	_brain = new Brain;
}

Cat::Cat(Cat const &other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat	&Cat::operator=(Cat const &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other) {
		type = other.type;
		*_brain = *other._brain;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

/* -------------------------------------------------------------------------- */

Brain	*Cat::getBrain() const {
	return (this->_brain);
}

/* -------------------------------------------------------------------------- */

void	Cat::makeSound() const {
	std::cout << "Miao!" << std::endl;
}
