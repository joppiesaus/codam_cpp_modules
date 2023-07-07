/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:16:51 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:16:51 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *mies;
	Zombie *bert;

	randomChump("janneke");	

	mies = newZombie("mies");

	randomChump("klaas");

	bert = newZombie("bert");

	delete bert;
	delete mies;
}
