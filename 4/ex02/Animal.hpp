/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 16:16:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/31 14:25:38 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
protected:
	Animal();
	Animal(const Animal& other);

public:
	virtual ~Animal();

	Animal& operator=(const Animal& rhs);

	virtual void makeSound() const = 0; // <-- pure virtual function

	std::string getType() const;

protected:
	std::string m_type;
};
