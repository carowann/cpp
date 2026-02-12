/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:37:17 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/12 16:11:05 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*_brain;
public:
	Dog();
	Dog(Dog const &other);
	Dog	&operator=(Dog const &other);
	~Dog();
	//
	Brain	*getBrain() const;
	//
	void	makeSound() const;
};

#endif