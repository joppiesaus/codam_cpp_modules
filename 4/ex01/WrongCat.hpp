/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 16:16:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/31 14:09:12 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Brain; // EPIC forward declaration

class Cat: public Animal
{
public:
	Cat();
	Cat(const Cat& other);
	~Cat();

	Cat& operator=(const Cat& rhs);

	void makeSound() const;

private:
	Brain *m_brain;
};
