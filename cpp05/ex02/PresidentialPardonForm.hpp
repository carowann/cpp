/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:07:49 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/18 15:24:16 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
public:
	//OCF
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &other);
	~PresidentialPardonForm();
	//
	PresidentialPardonForm(std::string const &target);
	//
	void	execute(Bureaucrat const &executor) const;
};

#endif