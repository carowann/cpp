/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:58:11 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/09 18:58:32 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap {
private:
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
public:
	//OCF
	ClapTrap();
	//copy constr
	//overload assegnazione
	~ClapTrap();

	ClapTrap(std::string name);
};


#endif