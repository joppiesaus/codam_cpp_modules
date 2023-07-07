#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	Form("PresidentialPardonForm", 25, 5),
	m_target("derp")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	Form("PresidentialPardonForm", 25, 5),
	m_target(target)
{
	
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	this->m_target = rhs.m_target;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	this->checkExecutionGrades(executor);

    std::cout << this->m_target << " has been pardoned by Zaphod Beeblebrox UwU" << std::endl;
}
