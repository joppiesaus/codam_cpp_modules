#pragma once

#include "Contact.hpp"

#define MAX_CONTACTS (8)

class Drawer;

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	void addContact(Contact contact);

	void displayContacts(const Drawer &drawer) const;

	bool isValidIndex(size_t index) const;
	bool isEmpty() const;

	const Contact& getContactAtIndex(size_t index) const;

private:
	void drawHeader(const Drawer &drawer) const;

	Contact m_contacts[MAX_CONTACTS];
	size_t	m_amountOfContacts;
	size_t	m_nextIndex;
};
