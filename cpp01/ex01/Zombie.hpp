/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:04:09 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/05 18:05:19 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

# define BLUE	"\033[0;34m"
# define RED	"\033[0;31m"
# define RESET	"\033[0m"

class	Zombie
{
private:
	std::string	_name;

public:
	Zombie( void );
	~Zombie( void );

	void	setName( std::string name  );
	void	announce( void );
	static Zombie*	zombieHorde( int N, std::string name );
};

#endif