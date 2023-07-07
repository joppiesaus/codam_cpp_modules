/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 16:34:33 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/12/08 21:00:34 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& st);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& ct);

	void attack(const std::string& target);

	void guardGate() const;

private:
	void initDefaultAttributes();
};
