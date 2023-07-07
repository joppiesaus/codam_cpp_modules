/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:15:42 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/12 14:15:42 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl = Harl();

	if (argc >= 2)
	{
		harl.complain(argv[1]);
		return 0;
	}

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("sdlfkjdsfljks");
	// haha no return here because it's c++ and WE CAN!
}
