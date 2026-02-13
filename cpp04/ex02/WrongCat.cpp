/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:53:35 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/13 15:05:55 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ------------------------------------ OCF ----------------------------------- */

WrongCat::WrongCat() : WrongAAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &other) : WrongAAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat	&WrongCat::operator=(WrongCat const &other) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void	WrongCat::makeSound() const {
	std::cout << "Wrong miao!" << std::endl;
}
