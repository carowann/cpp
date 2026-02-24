/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:44:29 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/24 14:26:12 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include	<stdint.h>
# include	<string>

struct Data
{
	int			value;
	std::string name;
};

class Serializer
{
private:
	//ocf
	Serializer();
	Serializer(Serializer const &);
	Serializer &operator=(Serializer const &);
	~Serializer();
public:
	static uintptr_t	serialize(Data* ptr);
	static Data			*deserialize(uintptr_t raw);
};


#endif