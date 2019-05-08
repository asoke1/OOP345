// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// String.cpp
// Abiodun Oke
// 2019/01/17

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;
//using namespace sict;
extern int INITIAL;

namespace sict {

	


	// a one-argument constructor 
	String::String(const char * str)
	{
		if (str != nullptr && str[0] != '\0')
		{
			strncpy(m_str, str, MAX);
			m_str[MAX] = '\0';

		
		}
		else {
			 m_str[0] = '\0';
		}
	}

	void String::display(std::ostream& os) const
	{
		
		os << m_str;

		
	}
	std::ostream & operator<<(std::ostream& os, const String & obj)
	{
		
		static int itemNumber = INITIAL;
		os << itemNumber << ": ";
		obj.display(os);
		
		
		itemNumber++;
		return os;
	}
}
