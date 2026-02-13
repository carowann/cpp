/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:54:08 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/12 16:18:01 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
private:
	std::string	_ideas[100];
public:
	//OCF
	Brain();
	Brain(Brain const &other);
	Brain	&operator=(Brain const &other);
	~Brain();
	//
	std::string	getIdea(int index) const;
	void		setIdea(int index, std::string idea);
};

#endif