/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:56:55 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/14 15:14:42 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include "iostream"

class HumanB
{
private:
	std::string	_name;
	Weapon		*_weapon;
public:
	HumanB( std::string name);
	void	attack() const;
	void	setWeapon( Weapon &weapon);
};

#endif