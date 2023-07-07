/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 15:30:07 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/05 12:42:00 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Grade.hpp"

#include <iostream>

class Bureaucrat; // i love forward declarations

class Form
{
public:
	Form();
	Form(const std::string name, const Grade minimumGradeToSign, const Grade minimumGradeToExecute);
	Form(const Form& other);
	~Form();
	
	Form& operator=(const Form& rhs);

	// this name is not a good name. it should be called sign() imo
	void beSigned(const Bureaucrat& bureaucrat);

	// void execute(const Bureaucrat& executor) const;

	const std::string& getName() const;
	bool isSigned() const;
	Grade getMinimumGradeToSign() const;
	Grade getMinimumGradeToExecute() const;

	// Annoyingly, I have to re-implement this instead of using the Bureaucrat's exception
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	void checkGradeInBounds() const;

	const std::string m_name;
	bool m_signed;
	const Grade m_minimumGradeToSign;
	const Grade m_minimumGradeToExecute;
};

std::ostream& operator<<(std::ostream &os, const Form& form);
