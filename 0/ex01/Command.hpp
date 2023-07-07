#pragma once

#include <iostream>

class PhoneBook;
class Drawer;

typedef int (*command_function_t)(PhoneBook &, const Drawer &);

class Command
{
public:
	std::string name;

	Command(std::string nname, std::string description, command_function_t func);
	~Command();

	void display() const;
	int execute(PhoneBook &pb, const Drawer &drawer) const;

private:
	std::string m_description;
	command_function_t m_functionToExecute;
};
