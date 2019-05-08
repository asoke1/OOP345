// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// String.h
// Abiodun Oke
// 2019/01/17

#ifndef SICT_STRING_H
#define SICT_STRING_H
#include <iostream>
#include <cstring>
#include "process.h"


namespace sict {
	const int MAX = 3;
	class String {
		char m_str[MAX + 1];
	public:
		// one-argument constructor
		String(const char* str);
		void display(std::ostream& os) const;

	};

	std::ostream& operator<<(std::ostream& os, const String& obj);

}

#endif // ! SICT_STRING_H
