/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/10 17:40:13 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/14 13:59:00 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <exception>

class Span
{
public:
	Span();
	Span(unsigned int N);
	~Span();
	Span(const Span& other);
	Span& operator=(const Span& rhs);

	void addNumber(int n);
	void fillRandom();

	// adds a range of numbers. begin and end must be the beginning and the end
	// of the iterator range you want to add from respectively.
	template <class T>
	void fillRange(T begin, T end)
	{
		size_t dist = std::distance(begin, end);
		if (dist > static_cast<size_t>(this->m_maxLength))
		{
			throw SpanFullException();
		}
		this->m_vec.insert(this->m_vec.begin(), begin, end);
		this->m_isSorted = false;
	}

	unsigned int shortestSpan();
	unsigned int longestSpan();

	class NotEnoughNumbers: public std::exception
	{
	public:
		virtual const char *what() const throw();	
	};
	class SpanFullException: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	void preSpanChecks();
	void sort();

	unsigned int m_maxLength;
	bool m_isSorted;
	std::vector<int> m_vec;
};
