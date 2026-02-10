/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:58:11 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/10 14:06:24 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "ClapTrap.h"

class ClapTrap {
private:
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
public:
	//OCF
	ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();
	//
	ClapTrap(std::string name);
	//
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};


#endif