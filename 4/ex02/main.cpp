/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/31 12:26:56 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include "Brain.hpp"

int main()
{
	//const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "type: " << cat->getType() << std::endl;
	std::cout << "type: " << dog->getType() << std::endl;

	cat->makeSound(); //will output the cat sound!
	dog->makeSound();

	// std::cout << "type: " << meta->getType() << std::endl;
	// meta->makeSound();

	// delete meta;
	delete dog;
	delete cat;


	// uncomment for instantiating test
	// Animal animal = Animal();

	// system("leaks animal");
}
