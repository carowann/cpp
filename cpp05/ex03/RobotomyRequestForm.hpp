/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:00:14 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/18 15:06:01 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;
public:
	//OCF
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &other);
	~RobotomyRequestForm();
	//
	RobotomyRequestForm(std::string const &target);
	//
	void	execute(Bureaucrat const &executor) const;
};

#endif