#include "Contact.hpp"
#include "Drawer.hpp"
#include "util.hpp"

#include <limits>
#include <stdlib.h> /* exit */

Contact::Contact()
{
}

Contact::Contact(std::string firstname, std::string lastname,
		std::string nickname, std::string darkestSecret,
		unsigned int number)
	: m_firstname(firstname),
	m_lastname(lastname),
	m_nickname(nickname),
	m_darkestSecret(darkestSecret),
	m_number(number)
{

}

Contact::~Contact()
{

}

void Contact::constructFromCin()
{
	std::cout << "First name: ";
	my_getline(m_firstname);
	std::cout << "Last name: ";
	my_getline(m_lastname);
	std::cout << "Nickname: ";
	my_getline(m_nickname);
	std::cout << "Phone number: ";
	std::cin >> m_number;
	while (std::cin.fail())
	{
		if (std::cin.eof())
		{
			exit(0);
		}
		std::cout << "That is not a phone number. Please try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> m_number;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Darkest secret: ";
	my_getline(m_darkestSecret);
	std::cout << "Succesfully added contact " << m_nickname << "!" << std::endl;
}

// displays the contact in the table, via the drawer.
void Contact::displayRow(const Drawer &drawer, size_t index) const
{
	drawer.beginRow();
	drawer.rowEntry(std::to_string(index));
	drawer.rowEntry(this->m_firstname);
	drawer.rowEntry(this->m_lastname);
	drawer.rowEntry(this->m_nickname);
	drawer.endRow();
	drawer.draw();
}

// displays the contact, with a line for each field.
void Contact::display() const
{
	std::cout << "First name:     " << this->m_firstname << "\n";
	std::cout << "Last name:      " << this->m_lastname << "\n";
	std::cout << "Nickname:       " << this->m_nickname << "\n";
	std::cout << "Phone number:   " << this->m_number << "\n";
	std::cout << "Darkest secret: " << this->m_darkestSecret << std::endl;
}
