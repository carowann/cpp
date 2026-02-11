/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:11:28 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/11 17:35:32 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Animal.h"

class Animal
{
protected:
	std::string	type;
public:
	//OCF
	Animal();
	Animal(Animal const &other);
	Animal &operator=(Animal const &other);
	virtual ~Animal();
	//
	std::string		getType(void) const;
	virtual void	makeSound() const;
};

#endif