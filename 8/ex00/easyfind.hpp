/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 18:11:01 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/10 17:37:21 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm> // std::find, iterator etc.

template <class T>
typename T::iterator easyfind(T& t, int toSearch)
{
	return std::find(t.begin(), t.end(), toSearch);
}
