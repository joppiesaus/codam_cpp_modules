/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:16:58 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:16:58 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl = Harl();

	if (argc >= 2)
	{
		harl.complain(argv[1]);
	}
	else
	{
		harl.complain("lol");
	}
}
