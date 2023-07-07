/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/29 14:14:07 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/31 14:17:28 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#define BRAIN_IDEAS_AMOUNT (100)

class Brain
{
public:
	Brain();
	Brain(const Brain& other);
	~Brain();

	Brain& operator=(const Brain& rhs);

	void fillIdeas();
	void displayIdeas() const;

private:
	std::string m_ideas[BRAIN_IDEAS_AMOUNT];
};
