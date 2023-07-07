/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 16:59:15 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/25 17:32:26 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ScavTrap jeff = ScavTrap("jeff");
	ScavTrap jeff_copy = ScavTrap(jeff);

	ScavTrap jill = ScavTrap("jill");

	jill.attack(jeff.getName());
	jeff.takeDamage(20);
	jeff.beRepaired(15);

	jill.guardGate();

	DiamondTrap dia = DiamondTrap("dia");
	dia.whoAmI();

	dia.attack("jan peter balkenende");

	dia.guardGate();
	dia.highFivesGuys();
}
