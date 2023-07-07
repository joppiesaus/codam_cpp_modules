/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 16:16:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/31 14:07:40 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Brain;

class Dog: public Animal
{
public:
	Dog();
	Dog(const Dog& other);
	~Dog();

	Dog& operator=(const Dog& rhs);

	void makeSound() const;

private:
	Brain *m_brain;
};
