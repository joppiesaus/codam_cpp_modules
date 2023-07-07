/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:16:40 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:18:49 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
public:
	Zombie(std::string name);
	~Zombie();

	void announce( void );

private:
	std::string m_name;
};

Zombie *newZombie( std::string name );
void randomChump( std::string name );
