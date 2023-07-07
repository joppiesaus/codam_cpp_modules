#include "Drawer.hpp"

#include <iomanip>

// NOTE: max_columns and max_col_size must be at least one.
Drawer::Drawer(size_t max_columns, size_t max_col_size) :
	m_max_columns(max_columns),
	m_max_col_size(max_col_size)
{

}

Drawer::~Drawer()
{

}

size_t	Drawer::calculate_row_size() const
{
	return ((this->m_max_col_size + 1) * this->m_max_columns + 2 - 1);
}

void Drawer::drawRowLine() const
{
	std::cout << "+";
	for (size_t i = 0; i < this->m_max_columns; i++)
	{
		std::cout << std::setfill('-') << std::setw(m_max_col_size + 1);
		std::cout << "+";
	}
	std::cout << "\n";
}

void Drawer::beginRow() const
{
	std::cout << "|";
}

void Drawer::rowEntry(std::string s) const
{
	if (s.length() <= this->m_max_col_size)
	{
		std::cout << std::setfill(' ') << std::setw(m_max_col_size);
		std::cout << s;
	}
	else
	{
		std::cout << s.substr(0, this->m_max_col_size - 1);
		std::cout << ".";
	}
	std::cout << "|";
}

void Drawer::endRow() const
{
	std::cout << "\n";
}

void Drawer::draw() const
{
	std::flush(std::cout);
}

