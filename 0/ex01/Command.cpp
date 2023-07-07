#include "Command.hpp"

Command::Command(std::string nname, std::string description, command_function_t fp) :
	name(nname),
	m_description(description),
	m_functionToExecute(fp)
{
}

Command::~Command()
{

}

int Command::execute(PhoneBook &pb, const Drawer &drawer) const
{
	return (*this->m_functionToExecute)(pb, drawer);
}

void Command::display() const
{
	std::cout << this->name << "  -  " << this->m_description << std::endl;
}
