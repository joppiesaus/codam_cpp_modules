#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("ShrubberyCreationForm", 145, 137),
	m_target("shrub")
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	Form("ShrubberyCreationForm", 145, 137),
	m_target(target)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	this->m_target = rhs.m_target;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	this->checkExecutionGrades(executor);

	std::ofstream outfile;
	outfile.open(this->m_target + "_shrubbery", std::ios::out | std::ios::trunc);
	outfile.exceptions( std::ofstream::failbit );

	// thanks ybakker
	outfile << "          '., " << "\n";
    outfile << "            'b      *" << "\n";
    outfile << "             '$    #." << "\n";
    outfile << "              $:   #:" << "\n";
    outfile << "              *#  @):" << "\n";
    outfile << "              :@,@):   ,.**:'" << "\n";
    outfile << "    ,         :@@*: ..**'" << "\n";
    outfile << "     '#o.    .:(@'.@*'' " << "\n";
    outfile << "        'bq,..:,@@*'   ,*" << "\n";
    outfile << "        ,p$q8,:@)'  .p*'" << "\n";
    outfile << "       '    '@@Pp@@*'" << "\n";
    outfile << "             Y7'.'" << "\n";
    outfile << "            :@):." << "\n";
    outfile << "           .:@:'." << "\n";
    outfile << "         .::(@:." << std::endl;

	outfile.close();
}
