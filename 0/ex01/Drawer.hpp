#pragma once

#include <iostream>

/* in theory, one could do error checking */
class Drawer
{
public:
	Drawer(size_t max_columns, size_t max_col_size);
	~Drawer();

	void drawRowLine() const;
	void beginRow() const;
	void rowEntry(std::string s) const;
	void endRow() const;
	void draw() const;

	size_t	calculate_row_size() const;

private:
	size_t	m_max_columns;
	size_t	m_max_col_size;
};
