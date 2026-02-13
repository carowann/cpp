/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:50:37 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/11 17:53:04 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGAANIMAL_HPP
# define WRONGAANIMAL_HPP

#include "AAnimal.h"

class WrongAAnimal
{
protected:
	std::string	type;
public:
	//OCF
	WrongAAnimal();
	WrongAAnimal(WrongAAnimal const &other);
	WrongAAnimal	&operator=(WrongAAnimal const &other);
	~WrongAAnimal();
	//
	std::string		getType(void) const;
	void			makeSound() const;
};

#endif