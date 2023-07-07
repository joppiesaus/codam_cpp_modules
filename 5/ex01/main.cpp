/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/08/31 18:48:27 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{	
	Bureaucrat jan = Bureaucrat("Jan Peter Balkenende", 20);
	Form form = Form("epic form", 50, 30);

	try
	{
		Form test = Form("yeet", 0, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	std::cout << form << std::endl;
	jan.signForm(form);
	std::cout << form << std::endl;


	Bureaucrat neelie = Bureaucrat("Neelie Kroes", 100);
	neelie.signForm(form);
}
