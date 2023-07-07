/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:16:34 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:16:34 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	const int amount = 6;

	Zombie *zombies;

	zombies = zombieHorde(amount, "Zombie MCzombieface");
	for (int i = 0; i < amount; i++)
	{
		zombies[i].announce();
	}

	delete[] zombies;
}
