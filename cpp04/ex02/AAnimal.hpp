/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:11:28 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/13 15:03:26 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include "AAnimal.h"

class AAnimal
{
protected:
	std::string	type;
public:
	//OCF
	AAnimal();
	AAnimal(AAnimal const &other);
	AAnimal	&operator=(AAnimal const &other);
	virtual	~AAnimal();
	//
	std::string		getType(void) const;
	virtual void	makeSound() const = 0;
};

#endif