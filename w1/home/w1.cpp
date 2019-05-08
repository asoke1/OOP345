// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// w1.cpp
// Abiodun Oke
// 2019/01/17
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "process.h"

using namespace std;
using namespace sict;

int INITIAL = 3;

int main(int argc, char* argv[]) {

	if (argc <= 1)
	{
		cout << "***Insufficient number of arguments***" << endl;
		return 1;
	}
	else {
		cout << "Command Line : ";
		for (int i = 0; i < argc; i++)
		{
			cout << argv[i] << " ";
		}
		cout << endl;
	}

	// calls the process function
	for (int i = 1; i < argc; i++)
	{
		process(argv[i]);
	}

	return 0;
}