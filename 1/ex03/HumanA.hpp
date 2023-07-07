/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 17:17:51 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:22:50 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

#include <iostream>

class HumanA
{
public:
	HumanA(std::string name, Weapon& weapon);


	void setWeapon(Weapon& weapon);

	void attack() const;

private:
	std::string m_name;
	Weapon& m_weapon;
};
