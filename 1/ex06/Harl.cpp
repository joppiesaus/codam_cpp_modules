/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:17:03 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:17:04 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

struct LevelStruct
{
	const std::string level;
	const Harl::Level Level;
};

// I hate everything about this
Harl::Level Harl::getLevel( std::string level ) const
{
	const LevelStruct levels[] = {
		{ "DEBUG", LDEBUG },
		{ "INFO", LINFO },
		{ "WARNING", LWARNING },
		{ "ERROR", LERROR }
	};

	for (size_t i = 0; i < sizeof(levels) / sizeof(LevelStruct); i++)
	{
		if (level == levels[i].level)
		{
			return levels[i].Level;
		}
	}
	return LCONTENT;
}

void Harl::complain( std::string level ) const
{
	switch (this->getLevel(level))
	{
		case LDEBUG:
			this->debug();
		case LINFO:
			this->info();
		case LWARNING:
			this->warning();
		case LERROR:
			this->error();
			break;

		default:
			this->content();
			break;
	};
}

void Harl::content( void ) const
{
	std::cout << "hmmm yum yum" << std::endl;
}

void Harl::debug( void ) const
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) const
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) const
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) const
{
    std::cout << "This is unacceptable! I want to speak to the manager now. *angry noises*" << std::endl;
}
