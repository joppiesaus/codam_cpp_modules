#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern::~Intern()
{
    
}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
    return *this;
}

static Form *createShrubbery(const std::string& target)
{
	Form *f = new ShrubberyCreationForm(target);
	return f;
}

static Form *createRobotomy(const std::string& target)
{
	Form *f = new RobotomyRequestForm(target);
	return f;
}

static Form *createPresident(const std::string& target)
{
	Form *f = new PresidentialPardonForm(target);
	return f;
}

typedef struct s_entry
{
	const std::string name;
	Form *(*func)(const std::string&);
} t_entry;

Form* Intern::makeForm(const std::string& formName, const std::string& target)
{
	// we're back in C I guess???
	const static t_entry entries[] = {
		{"shrubbery creation", &createShrubbery},
		{"robotomy request", &createRobotomy},
		{"presidential pardon", &createPresident}
	};

	for (size_t i = 0; i < sizeof(entries) / sizeof(t_entry); i++)
	{
		if (entries[i].name == formName)
		{
			Form *form = (*entries[i].func)(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "Intern failed to create a form, no such form ``" << formName << "\"" << std::endl;
	return nullptr;
}
