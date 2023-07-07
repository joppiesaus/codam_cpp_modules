/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 16:59:12 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/25 15:27:00 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void DiamondTrap::initDefaultAttributes()
{
	this->ClapTrap::m_name = this->m_name + "_clap_name";
	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDamage = 30;
	std::cout << "Constructed DiamondTrap " << this->m_name << "." << std::endl;
}

DiamondTrap::DiamondTrap()
{
	this->m_name = ClapTrap::DefaultName;
	this->initDefaultAttributes();
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->m_name = name;
	this->initDefaultAttributes();
}

DiamondTrap::DiamondTrap(const DiamondTrap& ct)
{	
	*this = ct;
	std::cout << "Copy constructor called for " << this->m_name << "." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructed DiamondTrap " << this->m_name << "." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ct)
{
	this->ClapTrap::m_name = ct.ClapTrap::m_name;
	this->m_name = ct.m_name;
	this->m_hitPoints = ct.m_hitPoints;
	this->m_energyPoints = ct.m_energyPoints;
	this->m_attackDamage = ct.m_attackDamage;
	return *this;
}


void DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const
{
	std::cout << "I am " << this->m_name << " and my ClapTrap name is " << this->ClapTrap::m_name << "." << std::endl;
}
