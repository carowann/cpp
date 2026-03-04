/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:45:03 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/04 12:18:46 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(MutantStack const &other);
	MutantStack	&operator=(MutantStack const &other);
	~MutantStack();
	typedef typename std::deque<T>::iterator				iterator;
	typedef typename std::deque<T>::const_iterator			const_iterator;
	typedef typename std::deque<T>::reverse_iterator		reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator	const_reverse_iterator;
	iterator				begin();
	const_iterator			begin() const;
	iterator				end();
	const_iterator			end() const;
	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;
};

# include "MutantStack.tpp"

#endif