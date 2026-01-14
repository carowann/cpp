/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:43:34 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/14 16:31:01 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. ";
	std::cout << "I really do!";
	std::cout << std::endl;
}

void	Harl::info( void )
{
	std::cout << GREEN "INFO: I cannot believe adding extra bacon costs more money. You did not put enough bacon in my burger!";
	std::cout << " If you did, I would not be asking for more!" RESET;
	std::cout << std::endl;
}

void	Harl::warning( void )
{
	std::cout << BLUE "WARNING: I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years, whereas you started working here just last month." RESET;
	std::cout << std::endl;
}

void	Harl::error( void )
{
	std::cout << RED "ERROR: This is unacceptable! I want to speak to the manager now." RESET;
	std::cout << std::endl;
}

void	Harl::complain( std::string level )
{
	void	(Harl::*funcs[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*funcs[i])();
			return ;
		}
	}
}
