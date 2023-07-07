/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/31 17:48:20 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b = Bureaucrat("piet", 0);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b = Bureaucrat("mies", 255);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat test = Bureaucrat("alex", 2);

	test.incrementGrade();
	std::cout << test << std::endl;
	try
	{
		test.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		int i = 0;
		while (true)
		{
			if (i > 144)
			{
				std::cout << test << std::endl;
			}
			test.decrementGrade();
			i++;
		}
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
