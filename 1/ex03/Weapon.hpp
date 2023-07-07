/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 17:19:30 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/10 17:19:41 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon
{
public:
	Weapon(std::string type);

	std::string getType() const;
	void setType(std::string type);

private:
	std::string m_type;
};
