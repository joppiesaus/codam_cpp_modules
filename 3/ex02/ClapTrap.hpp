/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 16:34:33 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/25 15:25:58 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& ct);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& ct);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	bool isDead() const;

	std::string getName() const;

	static const std::string DefaultName;

protected:
	std::string m_name;
	int	m_hitPoints;
	int m_energyPoints;
	int m_attackDamage;

private:
	void initDefaultAttributes();
};
