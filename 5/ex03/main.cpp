/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/02 17:50:00 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{	
	Intern intern = Intern();
	Bureaucrat jan = Bureaucrat("Jan Peter Balkenende", 5);
	
	Form *sform = intern.makeForm("shrubbery creation", "super");

	Form *form = intern.makeForm("derp", "yeet");
	(void)form;

	jan.executeForm(*sform);	
	

	std::cout << sform << std::endl;
	jan.signForm(*sform);
	std::cout << sform << std::endl;

	jan.executeForm(*sform);


	Bureaucrat neelie = Bureaucrat("Neelie Kroes", 72);
	RobotomyRequestForm rform = RobotomyRequestForm("seacucumber");

	neelie.signForm(rform);
	neelie.executeForm(rform);

	jan.executeForm(rform);
	jan.executeForm(rform);


	PresidentialPardonForm pform = PresidentialPardonForm();
	jan.signForm(pform);
	jan.executeForm(pform);

	delete sform;
}
