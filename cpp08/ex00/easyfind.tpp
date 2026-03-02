/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:13:35 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/02 18:00:08 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::const_iterator	easyfind(T const &container, int value) {
	typename T::const_iterator	it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
			throw (std::runtime_error("Value not found."));
	else
		return (it);
}
