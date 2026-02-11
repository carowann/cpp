/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:58:11 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/11 14:19:22 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "ClapTrap.h"

class ClapTrap {
private:
	std::string _name;
	unsigned int			_hitPoints;
	unsigned int			_energyPoints;
	unsigned int			_attackDamage;
public:
	//OCF
	ClapTrap();
	ClapTrap(ClapTrap const &other);
	ClapTrap &operator=(ClapTrap const &other);
	~ClapTrap();
	//
	ClapTrap(std::string const &name);
	//
	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif