/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 16:59:12 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/25 15:27:00 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::initDefaultAttributes()
{
	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDamage = 20;
	std::cout << "Constructed ScavTrap " << this->m_name << "." << std::endl;
}

ScavTrap::ScavTrap()
{
	this->initDefaultAttributes();
}

ScavTrap::ScavTrap(std::string name)
{
	this->m_name = name;
	this->initDefaultAttributes();
}

ScavTrap::ScavTrap(const ScavTrap& ct)
{	
	*this = ct;
	std::cout << "Copy constructor called for " << this->m_name << "." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructed ScavTrap " << this->m_name << "." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ct)
{
	this->m_name = ct.m_name;
	this->m_hitPoints = ct.m_hitPoints;
	this->m_energyPoints = ct.m_energyPoints;
	this->m_attackDamage = ct.m_attackDamage;
	return *this;
}


void ScavTrap::attack(const std::string& target)
{
	if (this->isDead())
	{
		std::cout << "ScavTrap " << m_name << " can't attack "
			<< target << ", because it is dead." << std::endl;
	}
	else if (this->m_energyPoints == 0)
	{
		std::cout << "ScavTrap " << m_name << " can't attack "
			<< target << ", it's out of energy points!" << std::endl;
	}
	else
	{
		this->m_energyPoints--;
		std::cout << "ScavTrap " << m_name << " attacks " << target
					<< ", causing " << m_attackDamage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate() const
{
	std::cout << "ScavTrap " << m_name << " is now in guard keeping mode(whatever that may mean)" << std::endl;
}
