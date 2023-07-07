#pragma once

#include <iostream>

class Drawer; // le epic forward declaration

class Contact
{
public:
	Contact();
	Contact(std::string firstname, std::string lastname,
		std::string nickname, std::string darkestSecret,
		unsigned int number);
	~Contact();

	void displayRow(const Drawer &drawer, size_t index) const;
	void display() const;

	void constructFromCin();

private:
	std::string		m_firstname;
	std::string		m_lastname;
	std::string		m_nickname;
	std::string		m_darkestSecret;
	unsigned int	m_number;
};
