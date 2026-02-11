/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:42:07 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/11 12:54:12 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	/* data */
public:
	//OCF
	FragTrap();
	FragTrap(FragTrap const &other);
	FragTrap &operator=(FragTrap const &other);
	~FragTrap();

	FragTrap(std::string const &name);
	void	highFivesGuys(void);
};


#endif