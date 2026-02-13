/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:37:22 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/13 15:06:08 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain	*_brain;
public:
	Cat();
	Cat(Cat const &other);
	Cat	&operator=(Cat const &other);
	~Cat();
	//
	Brain	*getBrain() const;
	//
	void	makeSound() const;
};

#endif