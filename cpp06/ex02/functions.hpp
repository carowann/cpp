/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:01:44 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/24 16:32:46 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include	"Base.hpp"
# include	<cstdlib>
# include	<ctime>
# include	<iostream>
# include	"A.hpp"
# include	"B.hpp"
# include	"C.hpp"

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif