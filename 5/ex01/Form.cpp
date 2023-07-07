#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() :
	m_name("hellish bureaucratic form from tax agency"),
	m_signed(false),
	m_minimumGradeToSign(100),
	m_minimumGradeToExecute(80)
{
	this->checkGradeInBounds();
}

Form::Form(const std::string name, const Grade minimumGradeToSign, const Grade minimumGradeToExecute) :
	m_name(name),
	m_signed(false),
	m_minimumGradeToSign(minimumGradeToSign),
	m_minimumGradeToExecute(minimumGradeToExecute)
{
	this->checkGradeInBounds();
}

Form::Form(const Form& other) :
	m_name(other.m_name),
	m_minimumGradeToSign(other.m_minimumGradeToSign),
	m_minimumGradeToExecute(other.m_minimumGradeToExecute)
{
    *this = other;
}

Form::~Form()
{

}

Form& Form::operator=(const Form& rhs)
{
    this->m_signed = rhs.m_signed;
	return *this;
}

// what to do when it is already signed? lol
void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->m_minimumGradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	this->m_signed = true;
}

const std::string& Form::getName() const
{
	return this->m_name;    
}

bool Form::isSigned() const
{
	return this->m_signed;    
}

Grade Form::getMinimumGradeToSign() const
{
	return this->m_minimumGradeToSign;    
}

Grade Form::getMinimumGradeToExecute() const
{
	return this->m_minimumGradeToExecute;    
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high. sorry.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low. rip";
}

void Form::checkGradeInBounds() const
{
	if (this->m_minimumGradeToSign < MAXIMUM_GRADE
		|| this->m_minimumGradeToExecute < MAXIMUM_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (this->m_minimumGradeToSign > MINIMUM_GRADE
		|| this->m_minimumGradeToExecute > MINIMUM_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form ``" << form.getName() << "\": requires grade "
		<< form.getMinimumGradeToSign() << " to sign(" 
		<< (form.isSigned() ? "currently signed" : "not currently signed")
		<< ") and " << form.getMinimumGradeToExecute() << " to execute.";
	return os;
}
