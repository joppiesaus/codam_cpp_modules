/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:52:10 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/08 13:59:45 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
T& min(T& a, T& b)
{
	return (a < b) ? a : b;
}

template <class T>
T& max(T& a, T& b)
{
	return (a > b) ? a : b;
}
