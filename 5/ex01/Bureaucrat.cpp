#include "Grade.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, Grade grade)
	: m_name(name)
{
	if (grade < MAXIMUM_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > MINIMUM_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->m_grade = grade;
}

const std::string& Bureaucrat::getName() const
{
	return this->m_name;    
}

Grade Bureaucrat::getGrade() const
{
	return this->m_grade;    
}

void Bureaucrat::incrementGrade()
{
    if (this->m_grade == MAXIMUM_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->m_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->m_grade == MINIMUM_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->m_grade++;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << "Bureaucrat " << this->m_name << " couldn't sign " << form.getName()
			<< " because the bureaucrat's grade was too low." << std::endl;
		return;
	}

	std::cout << "Bureaucrat " << this->m_name << " signed " << form.getName()
			<< std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

/// whyyy ._.
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! YOU SUCK!";
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Are you stoopid????";
}
