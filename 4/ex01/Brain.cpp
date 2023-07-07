/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/29 14:26:29 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/31 14:17:20 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain()
{
	this->fillIdeas();
}

Brain::Brain(const Brain& other)
{
    *this = other;
}

Brain::~Brain()
{
    
}

Brain& Brain::operator=(const Brain& rhs)
{
	for (size_t i = 0; i < BRAIN_IDEAS_AMOUNT; i++)
	{
		this->m_ideas[i] = rhs.m_ideas[i];
	}
	return *this;
}

void Brain::fillIdeas()
{
    static size_t n = 1;

	for (size_t i = 0; i < BRAIN_IDEAS_AMOUNT; i++)
	{
		this->m_ideas[i] = "idea " + std::to_string(n);
		if ((n & 0xf) == 0)
		{
			this->m_ideas[i] = "super " + this->m_ideas[i];
		}
		n++;
	}
}

void Brain::displayIdeas() const
{
    for (size_t i = 0; i < BRAIN_IDEAS_AMOUNT; i++)
	{
		std::cout << this->m_ideas[i] << std::endl;
	}
}
