/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 16:59:15 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/25 15:46:40 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap jeff = ScavTrap("jeff");
	ScavTrap jeff_copy = ScavTrap(jeff);

	ScavTrap jill = ScavTrap("jill");

	FragTrap alex = FragTrap("alex");

	jill.attack(jeff.getName());
	jeff.takeDamage(20);
	jeff.beRepaired(15);

	jill.guardGate();

	jeff.attack(alex.getName());
	alex.takeDamage(40);
	alex.highFivesGuys();

	alex.beRepaired(20);
}
