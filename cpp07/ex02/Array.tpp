/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:50:44 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/27 15:44:54 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(Array const &other) {
	_data = new T[other._size];
	_size = other._size;
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

template <typename T>
Array<T>::Array(unsigned int n) {
	_data = new T[n]();
	_size = n;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &other) {
	if (this != &other) {
		delete[] _data;
		_data = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int idx) {
	if (idx >= this->_size)
		throw (std::exception());
	return (this->_data[idx]);
}

template <typename T>
Array<T>::~Array() {
	delete[]_data;
}

template <typename T>
unsigned int	Array<T>::size() const {
	return (_size);
}
