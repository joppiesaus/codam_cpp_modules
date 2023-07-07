/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 16:34:33 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/25 17:32:38 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& st);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& ct);

	void attack(const std::string& target);

	void whoAmI() const;

private:
	void initDefaultAttributes();

	std::string m_name;
};
