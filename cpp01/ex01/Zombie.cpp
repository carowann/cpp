/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:04:02 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/14 15:16:08 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) : _name("")
{
}

Zombie::~Zombie()
{
	std::cout << _name << " has retired." << std::endl;
}

void	Zombie::setName( std::string name )
{
	if (!name.empty())
		_name = name;
}
void	Zombie::announce( void ) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


