// Workshop 2 - Copy and Move Semantics
// Text.cpp
// at Home
// Abiodun Oke
// 2019/01/25

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <iomanip>
#include <cstring>
#include "Text.h"
#include "Timekeeper.h"
using namespace std;

namespace sict {




	Text::Text()
	{
		m_name = nullptr;
		ct = 0;
	}

	Text::Text(string filename) : Text()
	{
		ifstream is(filename, std::ios::in);
		if (is.is_open()) {
			std::string line;
			while (getline(is, line)) {
				//getline(is, line);
				ct++;
			}
			m_name = new string[ct];
			is.clear();  // Reset
			is.seekg(0, std::ios_base::beg); // file position to begining

			for (size_t i = 0; i < ct; i++) {
				getline(is, m_name[i]);
			}
			is.close();
		}

	}

	// Copy constructor
	Text::Text(Text& src) : Text()
	{
		//m_name = nullptr;
		//ct = 0;
		*this = src;


	} // l-value

	  // copy assignment operator
	Text & Text::operator=(Text& src)
	{
		if (this != &src)
		{
			delete[] m_name;
			//m_name = nullptr;
			ct = src.ct;

			m_name = new string[ct];
			for (size_t i = 0; i < ct; i++)
			{
				m_name[i] = src.m_name[i];
			}

		}
		return *this;

	}

	// Destructor
	Text::~Text()
	{
		delete[] m_name;
		m_name = nullptr;
	}

	// Move consturctor
	Text::Text(Text&& src)
	{
		
		m_name = src.m_name;
		ct = src.ct;

		src.m_name = nullptr;
		src.ct = 0;
	}
		// Move Assignment 
	Text & Text::operator=(Text&& src)
	{
		
		if (this != &src)
		{
			delete[] m_name;
			m_name = src.m_name;
			ct = src.ct;

			src.m_name = nullptr;
			src.ct = 0;
		}
		return *this;

	} // taking r-value




	size_t Text::size() const
	{
		return ct;
	}

}
