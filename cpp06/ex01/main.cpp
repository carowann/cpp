/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:50:56 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/24 14:43:37 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "iostream"

int main(void) {
	Data	data;

	data.value = 42;
	data.name = "FortyTwo";

	std::cout << "Data value: " << data.value << std::endl;
	std::cout << "Data name: " << data.name << std::endl;

	uintptr_t raw = Serializer::serialize(&data);

	std::cout << "Original pointer:     " << &data << std::endl;
	std::cout << "Serialized value:     " << raw << std::endl;
	std::cout << "Serialized value (hex): " << (void*)raw << std::endl;
	std::cout << "Deserialized pointer: " << Serializer::deserialize(raw) << std::endl;
	std::cout << "Pointers match: " << (&data == Serializer::deserialize(raw) ? "YES" : "NO") << std::endl;

	Data* result = Serializer::deserialize(raw);
	std::cout << "Data value: " << result->value << std::endl;
	std::cout << "Data name: " << result->name << std::endl;
}
