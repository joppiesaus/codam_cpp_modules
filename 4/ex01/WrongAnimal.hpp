/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 16:16:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/28 18:34:52 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
public:
	Animal();
	Animal(const Animal& a);
	~Animal();

	Animal& operator=(const Animal& a);

	void makeSound() const;

	std::string getType() const;

protected:
	std::string m_type;
};
