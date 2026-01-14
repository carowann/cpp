/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:39:23 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/14 17:31:03 by cwannhed         ###   ########.fr       */
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

Level	Harl::levelToCode( std::string level ) {
	if (level == "DEBUG")
		return (DEBUG);
	if (level == "INFO")
		return (INFO);
	if (level == "WARNING")
		return (WARNING);
	if (level == "ERROR")
		return (ERROR);
	return (INVALID);
}

void	Harl::complain( std::string level )
{
	Level	codeLevel;

	codeLevel = Harl::levelToCode(level);
	switch (codeLevel) {
	case DEBUG:
		Harl::debug();
	case INFO:
		Harl::info();
	case WARNING:
		Harl::warning();
	case ERROR:
		Harl::error();
		break;
	default:
		std::cout << BOLD "Probably complaining about insignificant problems" RESET << std::endl;
		break;
	}
}
