/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:15:30 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:15:32 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

typedef void (*harl_func)( void );

struct Level
{
	const std::string level;
	const harl_func func;
};

void Harl::complain( std::string level )
{
    const Level levels[] = {
		{ "DEBUG", &Harl::debug },
		{ "INFO", &Harl::info },
		{ "WARNING", &Harl::warning },
		{ "ERROR", &Harl::error }
	};

	for (size_t i = 0; i < sizeof(levels) / sizeof(Level); i++)
	{
		if (level == levels[i].level)
		{
			(*levels[i].func)();
			return;
		}
	}
	this->content();
}

void Harl::content( void ) const
{
	std::cout << "hmmm yum yum" << std::endl;
}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now. *angry noises*" << std::endl;
}
