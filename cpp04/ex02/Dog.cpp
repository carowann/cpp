/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:37:25 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/13 15:05:55 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ------------------------------------ OCF ----------------------------------- */

Dog::Dog() : AAnimal() {
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	_brain = new Brain;
}

Dog::Dog(Dog const &other) : AAnimal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Dog	&Dog::operator=(Dog const &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		type = other.type;
		*_brain = *other._brain;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

/* -------------------------------------------------------------------------- */

Brain	*Dog::getBrain() const {
	return (this->_brain);
}

/* -------------------------------------------------------------------------- */

void	Dog::makeSound() const {
	std::cout << "Bau!" << std::endl;
}
