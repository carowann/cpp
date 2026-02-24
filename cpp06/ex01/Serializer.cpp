/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:45:25 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/24 14:15:54 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ------------------------------------ OCF ----------------------------------- */

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &) {};

Serializer &Serializer::operator=(Serializer const &) { return (*this); };

Serializer::~Serializer() {}

/* -------------------------------------------------------------------------- */

uintptr_t	Serializer::serialize(Data* ptr) {
	uintptr_t	uintPtr;

	uintPtr = reinterpret_cast<uintptr_t>(ptr);
	return (uintPtr);
}

Data	*Serializer::deserialize(uintptr_t raw) {
	Data	*data;

	data = reinterpret_cast<Data *>(raw);
	return (data);
}
