/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 16:16:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/31 15:28:40 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
public:
	Animal();
	Animal(const Animal& other);
	virtual ~Animal();

	Animal& operator=(const Animal& rhs);

	virtual void makeSound() const;

	std::string getType() const;

protected:
	std::string m_type;
};
