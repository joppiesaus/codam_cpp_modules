/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:16:46 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:16:47 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) :
	m_name(name)
{
	this->announce();
}

Zombie::~Zombie()
{
	std::cout << this->m_name << " has been destroyed." << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
