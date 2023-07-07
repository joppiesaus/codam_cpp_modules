/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 16:43:49 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/11 17:38:45 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include <string.h> // strerror
#include <sys/errno.h> // strerror(errno)

static void my_replace(std::string& line, std::string toFind, std::string toReplace)
{
	if (toFind.empty())
	{
		return;
	}

	while (true)
	{
		size_t index = line.find(toFind);
		if (index != toFind.npos)
		{
			line.erase(index, toFind.length());
			line.insert(index, toReplace);
		}
		else
		{
			break;
		}
	}
}

int main(int argc, char **argv)
{
	std::ifstream infile;
	std::ofstream outfile;

	if (argc < 3)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <string to search> <string to replace with>\n";
		return 1;
	}

	infile.open(argv[1], std::ios::in);
	if (!infile.is_open())
	{
		std::cerr << "unable to open input file \"" << argv[1] << "\": " << strerror(errno) << "\n";
		return 1;
	}
	outfile.open(std::string(argv[1]) + ".replace", std::ios::out | std::ios::trunc);
	if (!outfile.is_open())
	{
		std::cerr << "unable to open output file \"" << argv[1] << ".replace\": " << strerror(errno) << "\n";
		return 1;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		if (infile.eof() || infile.bad())
		{
			break;
		}
		my_replace(line, std::string(argv[2]), std::string(argv[3]));
		outfile << line << "\n";
	}
	infile.close();
	outfile.close();
	return 0;
}
