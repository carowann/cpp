/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:05:31 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/19 14:17:17 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	//OCF
	Intern();
	Intern(Intern const &);
	Intern &operator=(Intern const &);
	~Intern();
	//
	AForm	*makeForm(std::string name, std::string form);

};

AForm	*createShrubbery(std::string target);
AForm	*createRobotomy(std::string target);
AForm	*createPardon(std::string target);

#endif