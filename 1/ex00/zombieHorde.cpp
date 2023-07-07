/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:16:43 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:16:43 by jobvan-d      ########   odam.nl         */
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
