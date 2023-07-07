/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 17:19:28 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:22:35 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& weapon) :
	m_name(name),
	m_weapon(weapon)
{
    
}

void HumanA::setWeapon(Weapon& weapon)
{
	this->m_weapon = weapon;
}

void HumanA::attack() const
{
    std::cout << this->m_name << " attacks with their " << this->m_weapon.getType() << std::endl;
}
