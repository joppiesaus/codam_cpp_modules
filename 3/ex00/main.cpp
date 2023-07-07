/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 16:59:15 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/25 15:33:43 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap jeff = ClapTrap("jeff");
	ClapTrap jeff_copy = ClapTrap(jeff);

	ClapTrap jill = ClapTrap("jill");

	jill.attack(jeff.getName());
	jeff.takeDamage(0);
	jeff.beRepaired(15);


	jeff.takeDamage(10000);
	jeff.attack(jill.getName());

	jeff.takeDamage(10000);
	jeff.beRepaired(10000);

}
