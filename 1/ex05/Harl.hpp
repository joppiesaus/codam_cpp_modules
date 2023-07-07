/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:15:38 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:15:38 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl
{
public:
	void complain( std::string level );
	
private:
	static void debug( void );
	static void info( void );
	static void warning( void );
	static void error( void );
	void content( void ) const;
};
