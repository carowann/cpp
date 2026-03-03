/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:45:03 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/03 18:40:25 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(MutantStack const &other);
	MutantStack	&operator=(MutantStack const &other);
	~MutantStack();
	typedef typename std::deque<T>::iterator		iterator;
	typedef typename std::deque<T>::const_iterator	const_iterator;
	iterator		begin();
	const_iterator	begin() const;
	iterator		end();
	const_iterator	end() const;
};

# include "MutantStack.tpp"

#endif