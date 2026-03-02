/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:10:46 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/02 18:30:35 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
private:
	unsigned int _N;
	//container per memorizzare gli interi, forse vector?
public:
	Span();
	Span(unsigned int N);
	Span(Span const &other);
	Span &operator=(Span const &other);

	void	addNumber(int number);
	int		shortestSpan();
	int		longestSpan();

	~Span();
};


#endif

