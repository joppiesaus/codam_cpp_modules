#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, unsigned char grade)
	: m_name(name)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->m_grade = grade;
}

const std::string& Bureaucrat::getName() const
{
	return this->m_name;    
}

unsigned char Bureaucrat::getGrade() const
{
	return this->m_grade;    
}

void Bureaucrat::incrementGrade()
{
    if (this->m_grade == 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->m_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->m_grade == 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->m_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << static_cast<unsigned int>(bureaucrat.getGrade()) << ".";
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
