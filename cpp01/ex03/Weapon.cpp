/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:47:10 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/12 13:13:53 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
}

const std::string	&Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType( std::string type )
{
	if (!type.empty())
		_type = type;
}
