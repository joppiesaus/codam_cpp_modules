#include <iostream>

// prints a string to stdout in uppercase.
void	print_uppercase(std::string s)
{
	std::string::iterator it;	// I wish I could use the auto keyword here...

	for (it = s.begin(); it != s.end(); it++)
	{
		*it = std::toupper(*it);
	}
	std::cout << s;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		print_uppercase(std::string(argv[i]));
	}
	std::cout << std::endl;
}
