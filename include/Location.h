#pragma once
#include <iosfwd>

struct Location
{
	int m_col = 0;
	int m_row = 0; 

	Location() = default;
	Location(int row, int col) : m_row(row), m_col(col) {}
};

struct Special
{
	bool m_specialMov = false;

	Special() = default;
	Special(bool curr_posi) : m_specialMov(curr_posi) {}
};


