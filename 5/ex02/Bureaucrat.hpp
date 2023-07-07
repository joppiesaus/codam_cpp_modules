/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 16:16:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/02 15:19:49 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Grade.hpp"

class Form;

class Bureaucrat
{
public:
	Bureaucrat(const std::string& name, Grade grade);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	const std::string& getName() const;
	Grade getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(Form& form);
	void executeForm(const Form& form);

private:
	const std::string m_name;
	Grade m_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
