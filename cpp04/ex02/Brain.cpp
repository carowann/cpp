/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:54:13 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/12 16:19:49 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ------------------------------------ OCF ----------------------------------- */

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(Brain const &other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain default destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

std::string	Brain::getIdea(int index) const {
	if (index < 0 || index >= 100) {
		std::cerr << "Error: index out of bounds." << std::endl;
		return ("");
	}
	return (this->_ideas[index]);
}

void	Brain::setIdea(int index, std::string idea) {
	if (index < 0 || index >= 100) {
		std::cerr << "Error: index out of bounds." << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
}
