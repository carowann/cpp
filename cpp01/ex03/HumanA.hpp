/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:56:11 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/14 15:14:50 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include "iostream"

class HumanA
{
private:
	std::string	_name;
	Weapon		&_weapon;
public:
	HumanA( std::string name, Weapon &weapon );
	void	attack() const;
};

#endif
