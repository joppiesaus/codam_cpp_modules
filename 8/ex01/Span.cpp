/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 13:48:14 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/14 14:06:08 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <random>

Span::Span()
	: m_maxLength(0),
	m_isSorted(true)
{
	
}

Span::Span(unsigned int N)
	: m_maxLength(N),
	m_isSorted(true)
{

}

Span::Span(const Span& other) 
{
	*this = other;
}

Span::~Span()
{

}

Span& Span::operator=(const Span& rhs)
{
	this->m_maxLength = rhs.m_maxLength;
	this->m_isSorted = rhs.m_isSorted;
	this->m_vec = rhs.m_vec;
	return *this;
}

void Span::addNumber(int n)
{
	if (this->m_vec.size() == m_maxLength)
	{
		throw Span::SpanFullException();
	}
	this->m_vec.push_back(n);
	m_isSorted = false;
}

static int generateElement()
{
	// alternative:
	// static int i = 0;
	// i += 5;
	// return i;

	return rand();
}

// fills the span with random numbers
void Span::fillRandom()
{
	srand(0xfa1afe1 + m_maxLength);
	this->m_vec.resize(m_maxLength);
	std::generate(this->m_vec.begin(), this->m_vec.end(), generateElement);
	m_isSorted = false;
}

unsigned int Span::shortestSpan()
{
	this->preSpanChecks();

	unsigned int shortestSpan = std::numeric_limits<unsigned int>::max();

	std::vector<int>::iterator it;
	for (it = this->m_vec.begin(); (it + 1) != this->m_vec.end(); it++)
	{
		unsigned int currentSpan = static_cast<unsigned int>(*(it + 1)) -
			static_cast<unsigned int>(*it);
		if (currentSpan < shortestSpan)
		{
			shortestSpan = currentSpan;
		}
	}
	return shortestSpan;
}

unsigned int Span::longestSpan()
{
	this->preSpanChecks();
	return (static_cast<unsigned int>(this->m_vec.back())
		- static_cast<unsigned int>(this->m_vec.front()));
}

// does checks before returning a span, such as if the array is sorted,
// or wether there are enough numbers.
void Span::preSpanChecks()
{
	if (this->m_vec.size() < 2)
	{
		throw Span::NotEnoughNumbers();
	}
	else if (!m_isSorted)
	{
		this->sort();
	}
}

void Span::sort()
{
	std::sort(this->m_vec.begin(), this->m_vec.end());
	this->m_isSorted = true;
}

const char *Span::NotEnoughNumbers::what() const throw()
{
	return "Span doesn't have enough numbers to return a span";
};

const char *Span::SpanFullException::what() const throw()
{
	return "Span is full";
};
