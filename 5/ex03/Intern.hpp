/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 17:10:43 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/02 17:47:32 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Form;

class Intern
{
public:
	// why do i have to do the orthodox canonical form here...
	// this exercise sucks... sigh.
	Intern();
	Intern(const Intern& other);
	~Intern();

	Intern& operator=(const Intern& rhs);

	Form* makeForm(const std::string& formName, const std::string& target);
};
