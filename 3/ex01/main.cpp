/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 16:59:15 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/25 15:33:11 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap jeff = ScavTrap("jeff");
	ScavTrap jeff_copy = ScavTrap(jeff);

	ScavTrap jill = ScavTrap("jill");

	jill.attack(jeff.getName());
	jeff.takeDamage(20);
	jeff.beRepaired(15);

	jill.guardGate();

	jeff.takeDamage(10000);
	jeff.attack(jill.getName());

	jeff.takeDamage(10000);
	jeff.beRepaired(10000);
}
