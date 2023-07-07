/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 17:19:31 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/10 17:19:41 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) :
	m_type(type)
{

}

std::string Weapon::getType() const
{
    return this->m_type;
}

void Weapon::setType(std::string type)
{
	this->m_type = type;
}

