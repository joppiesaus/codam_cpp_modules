#include "PhoneBook.hpp"
#include "Drawer.hpp"

PhoneBook::PhoneBook() :
	m_amountOfContacts(0)
{

}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::addContact(Contact contact)
{
	m_contacts[m_nextIndex] = contact;
	m_amountOfContacts++;
	if (m_amountOfContacts > MAX_CONTACTS)
	{
		m_amountOfContacts = MAX_CONTACTS;
	}
	m_nextIndex = (m_nextIndex + 1) % MAX_CONTACTS;
}

void PhoneBook::displayContacts(const Drawer &drawer) const
{
	drawer.drawRowLine();
	this->drawHeader(drawer);
	drawer.drawRowLine();

	for (size_t i = 0; i < m_amountOfContacts; i++)
	{
		m_contacts[i].displayRow(drawer, i);
	}

	drawer.drawRowLine();
}

bool PhoneBook::isValidIndex(size_t index) const
{
	return (index < this->m_amountOfContacts);
}

bool PhoneBook::isEmpty() const
{
	return (this->m_amountOfContacts == 0);
}

const Contact& PhoneBook::getContactAtIndex(size_t index) const
{
	if (!this->isValidIndex(index))
	{
		throw std::out_of_range("No such index");
	}
	return m_contacts[index];
}

// Ideally, you want to do this in the drawer class, but whatever.
void PhoneBook::drawHeader(const Drawer &drawer) const
{
	drawer.beginRow();
	drawer.rowEntry("index   ");
	drawer.rowEntry("first name");
	drawer.rowEntry("last name");
	drawer.rowEntry("nickname ");
	drawer.endRow();
}
