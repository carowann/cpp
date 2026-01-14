/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:40:12 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/14 17:39:52 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

# define BOLD	"\033[1m"
# define BLUE	"\033[0;34m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define RESET	"\033[0m"

typedef enum e_level {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	INVALID
} Level;

class Harl
{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
public:
	void	complain( std::string level );
	Level	levelToCode( std::string level );
};

#endif