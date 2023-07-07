/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 16:59:12 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/25 15:42:11 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void FragTrap::initDefaultAttributes()
{
	this->m_hitPoints = 100;
	this->m_energyPoints = 100;
	this->m_attackDamage = 30;
	std::cout << "Constructed FragTrap " << this->m_name << "." << std::endl;
}

FragTrap::FragTrap()
{
	this->initDefaultAttributes();
}

FragTrap::FragTrap(std::string name)
{
	this->m_name = name;
	this->initDefaultAttributes();
}

FragTrap::FragTrap(const FragTrap& ct)
{	
	*this = ct;
	std::cout << "Copy constructor called for " << this->m_name << "." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructed FragTrap " << this->m_name << "." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& ct)
{
	this->m_name = ct.m_name;
	this->m_hitPoints = ct.m_hitPoints;
	this->m_energyPoints = ct.m_energyPoints;
	this->m_attackDamage = ct.m_attackDamage;
	return *this;
}


void FragTrap::attack(const std::string& target)
{
	if (this->isDead())
	{
		std::cout << "FragTrap " << m_name << " can't attack "
			<< target << ", because it is dead." << std::endl;
	}
	else if (this->m_energyPoints == 0)
	{
		std::cout << "FragTrap " << m_name << " can't attack "
			<< target << ", it's out of energy points!" << std::endl;
	}
	else
	{
		this->m_energyPoints--;
		std::cout << "FragTrap " << m_name << " attacks " << target
					<< ", causing " << m_attackDamage << " points of damage!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << m_name << " high fives or something like that idk" << std::endl;
}
