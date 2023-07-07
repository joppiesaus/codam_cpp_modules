/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 17:19:34 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:24:45 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		Weapon sword = Weapon("sword");
		HumanA bob("Bob", club);
		bob.attack();
		bob.setWeapon(sword);
		bob.setWeapon(nullptr);
		
		//club.setType("longsword");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("trebuchet");
		jim.attack();
	}

	return 0;
}
