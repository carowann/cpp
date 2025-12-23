/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:16:32 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/23 11:58:25 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class	Zombie
{
private:

	std::string	_name;

	Zombie( void );

public:

	Zombie( std::string name );
	~Zombie( void );

	void			announce( void );
	static Zombie*	newZombie( std::string name );
	static void		randomChump( std::string name );
};

#endif