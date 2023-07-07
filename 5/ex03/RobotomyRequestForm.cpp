#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	Form("RobotomyRequestForm", 72, 45),
	m_target("robot")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	Form("RobotomyRequestForm", 72, 45),
	m_target(target)
{
	
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	this->m_target = rhs.m_target;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    static size_t   i = 0;

	this->checkExecutionGrades(executor);

    std::cout << "*drilling noises*" << std::endl;
    std::cout << "..." << std::endl;

    i++;
    if (i % 2 == 0)
    {
        std::cout << this->m_target << " has succesfully been robotomized!" << std::endl;
    }
    else
    {
        std::cout << this->m_target << " robotomy has failed! Proceeding with a lobotomy instead." << std::endl;
    }
}
