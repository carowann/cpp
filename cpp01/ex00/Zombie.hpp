/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:16:32 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/22 19:41:50 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
private:
	std::string	_name;

	Zombie( void );
	void	announce( void );

public:
	Zombie( std::string name );
	~Zombie( void );
	Zombie* newZombie( std::string name );
	void Zombie::randomChump( std::string name )
};

#endif