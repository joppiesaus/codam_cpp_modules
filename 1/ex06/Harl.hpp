/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:17:00 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:17:01 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl
{
public:
	enum Level
	{
		LDEBUG,
		LINFO,
		LWARNING,
		LERROR,
		LCONTENT
	};

	Level getLevel( std::string level ) const;
	void complain( std::string level ) const;
	
private:
	void debug( void ) const;
	void info( void ) const;
	void warning( void ) const;
	void error( void ) const;
	void content( void ) const;
};
