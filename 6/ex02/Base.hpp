/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 21:19:20 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/07 17:06:46 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base
{
public:
	virtual ~Base() {};
};

class A: public Base { };
class B: public Base { };
class C: public Base { };
