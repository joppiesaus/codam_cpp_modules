/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/29 16:18:45 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include "Brain.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "type: " << cat->getType() << std::endl;
	std::cout << "type: " << dog->getType() << std::endl;

	cat->makeSound(); //will output the cat sound!
	dog->makeSound();

	std::cout << "type: " << meta->getType() << std::endl;
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;

	size_t i;
	Animal*	animals[100];

	for (i = 0; i < 50; i++)
	{
		animals[i] = new Cat();
	}
	for (; i < 100; i++)
	{
		animals[i] = new Dog();
	}

	for (i = 0; i < 100; i++)
	{
		// animals[i]->makeSound();
		delete animals[i];
	}

	std::cout << "=========  DEEP COPY TEST  =========" << std::endl;
	{
		Brain brain1;
		Brain brain2;

		brain1 = Brain();
		brain2 = Brain(brain1);
		brain1.fillIdeas();

		std::cout << "=========  BRAIN1  =========" << std::endl;
		brain1.displayIdeas();
		std::cout << "=========  END BRAIN1  =========" << std::endl;
		std::cout << "=========  BRAIN2  =========" << std::endl;
		brain2.displayIdeas();
		std::cout << "=========  END BRAIN2  =========" << std::endl;
	}

	// system("leaks animal");
}
