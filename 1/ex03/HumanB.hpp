/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 17:19:26 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/10 17:19:38 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon; // le epic forward declaration

class HumanB
{
public:
	HumanB(std::string name);

	void setWeapon(Weapon& weapon);
	void attack() const;

private:
	std::string m_name;
	Weapon* m_weapon;
};
