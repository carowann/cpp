/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:15:19 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/23 12:01:28 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	zombie1("Pippo");
	Zombie	*zombie;

	zombie = NULL;
	zombie = Zombie::newZombie("Pluto");
	Zombie::randomChump("Zombie random");
	delete zombie;
	zombie = NULL;
	return (0);
}
