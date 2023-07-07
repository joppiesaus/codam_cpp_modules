/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 17:19:27 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/10 17:19:39 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include "Weapon.hpp"

HumanB::HumanB(std::string name) :
	m_name(name),
	m_weapon(nullptr)
{
   
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->m_weapon = &weapon;
}

void HumanB::attack() const
{
	if (m_weapon == nullptr)
	{
		std::cout << this->m_name << " has no weapon, and proceeds to attack with their bare fists!" << std::endl;
	}
	else
	{
    	std::cout << this->m_name << " attacks with their " << this->m_weapon->getType() << std::endl;
	}
}
