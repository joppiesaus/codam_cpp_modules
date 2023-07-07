/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:16:27 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:16:27 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie( std::string name )
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}

void randomChump( std::string name )
{
	Zombie zombie = Zombie(name);
}

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
	{
		std::cerr << "amount of zombies must be at least 1!" << std::endl;
		return nullptr;
	}
	
	Zombie* zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
	}

	return zombies;
}
