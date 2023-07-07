/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 16:59:12 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/25 15:26:49 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

const std::string ClapTrap::DefaultName = "DEFAULT";

void ClapTrap::initDefaultAttributes()
{
	this->m_hitPoints = 10;
	this->m_energyPoints = 10;
	this->m_attackDamage = 0;
	std::cout << "Constructed ClapTrap " << this->m_name << "." << std::endl;
}

ClapTrap::ClapTrap() :
	m_name(this->DefaultName)
{
	this->initDefaultAttributes();
}

ClapTrap::ClapTrap(std::string name) :
	m_name(name)
{
	this->initDefaultAttributes();
}

ClapTrap::ClapTrap(const ClapTrap& ct)
{	
	*this = ct;
	std::cout << "Copy constructor called for " << this->m_name << "." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructed ClapTrap " << this->m_name << "." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ct)
{
	this->m_name = ct.m_name;
	this->m_hitPoints = ct.m_hitPoints;
	this->m_energyPoints = ct.m_energyPoints;
	this->m_attackDamage = ct.m_attackDamage;
	return *this;
}

// returns true when the claptrap is dead
bool ClapTrap::isDead() const
{
	return (this->m_hitPoints <= 0);
}

// shouldn't target be a claptrap?????!
void ClapTrap::attack(const std::string& target)
{
	if (this->isDead())
	{
		std::cout << "ClapTrap " << m_name << " can't attack "
			<< target << ", because it is dead." << std::endl;
	}
	else if (this->m_energyPoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " can't attack "
			<< target << ", it's out of energy points!" << std::endl;
	}
	else
	{
		this->m_energyPoints--;
		std::cout << "ClapTrap " << m_name << " attacks " << target
					<< ", causing " << m_attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->m_hitPoints -= amount;
	std::cout << "ClapTrap " << m_name << " takes " << amount << " damage(hp now " << m_hitPoints << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->isDead())
	{
		std::cout << "ClapTrap " << m_name
			<< " can't repair itself, it's dead!" << std::endl;
	}
	else if (this->m_energyPoints == 0)
	{
		std::cout << "ClapTrap " << m_name
			<< " can't repair itself, it's out of energy points!" << std::endl;
	}
	else
	{
		this->m_hitPoints += amount;
		this->m_energyPoints--;
		std::cout << "ClapTrap " << m_name << " is repaired with " << amount << " hitpoints(hp: " << this->m_hitPoints << ", ep: " << this->m_energyPoints <<  ")" << std::endl;
	}
}

std::string ClapTrap::getName() const
{
	return this->m_name;
}
