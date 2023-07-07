#include "Contact.hpp"
#include "Command.hpp"
#include "Drawer.hpp"
#include "PhoneBook.hpp"
#include "util.hpp"

#define N_COMMANDS (3)

#include <stdlib.h> /* exit */

static int addContactCmd(PhoneBook &pb, const Drawer &drawer)
{
	Contact contact;

	(void)drawer; // to surpress compiler warnings
	contact.constructFromCin();
	pb.addContact(contact);
	return (1);
}

static int searchCmd(PhoneBook &pb, const Drawer &drawer)
{
	size_t index;

	if (pb.isEmpty())
	{
		std::cout << "Phonebook is empty. Please add a contact using the ADD command." << std::endl;
		return 1;
	}

	pb.displayContacts(drawer);
	std::cout << "Please enter the index of the contact you want to look at: ";
	std::cin >> index;
	while (std::cin.fail() || !pb.isValidIndex(index))
	{
		if (std::cin.eof())
		{
			exit(0);
		}
		std::cout << "Invalid index. Please try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> index;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	pb.getContactAtIndex(index).display();
	return (1);
}

static int exitCmd(PhoneBook &pb, const Drawer &drawer)
{
	(void)drawer;
	(void)pb;
	std::cout << "Bye!" << std::endl;
	return (0);
}

// returns the index of the command matching the cmd(name of the command).
// ideally, you'd use exceptions but too new to c++, I am sure this will happen
// later on in the modules.
// Actually, you'd probably even write a class for this.
int tryFindFunction(const std::string &cmd, const Command commands[N_COMMANDS])
{
	for (int i = 0; i < N_COMMANDS; i++)
	{
		if (cmd == commands[i].name)
		{
			return i;
		}
	}
	return -1;
}

int	main()
{
	Drawer drawer = Drawer(4, 10);
	PhoneBook book = PhoneBook();

	Command commands[] = {
		Command("ADD", "Adds a contact to the phonebook", &addContactCmd),
		Command("SEARCH", "Search through the phonebook", &searchCmd),
		Command("EXIT", "Exits the program", &exitCmd)
	};


	std::cout << "Welcome to the crappy awesome phonebook software, by jobvan-d." << std::endl;

	while (true)
	{
		std::string cmd;

		std::cout << "Enter a command:\n";
		for (size_t i = 0; i < N_COMMANDS; i++)
		{
			commands[i].display();
		}

		my_getline(cmd);

		int	index = tryFindFunction(cmd, commands);
		if (index != -1)
		{
			std::cout << std::endl;
			if (!commands[index].execute(book, drawer))
			{
				return 0;
			}
			std::cout << std::endl;
			continue;
		}
		std::cout << "No such command \"" << cmd << "\", please try again." << std::endl;
	}
}
