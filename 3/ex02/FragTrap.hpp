/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 16:34:33 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/25 15:40:50 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& st);
	~FragTrap();

	FragTrap& operator=(const FragTrap& ct);

	void attack(const std::string& target);

	void highFivesGuys(void) const;

private:
	void initDefaultAttributes();
};
