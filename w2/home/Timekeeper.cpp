
// Workshop 2 - Copy and Move Semantics
// Timekeeper.cpp
// Abiodun Oke
// 2019/01/24
#include <iostream>
#include <iomanip>
#include <chrono>
#include "Timekeeper.h"
using namespace std;

namespace sict {



	Timekeeper::Timekeeper()
	{
		//noOfrecord = 0;
	}

	void Timekeeper::start()
	{
		startTimeObj = std::chrono::steady_clock::now();
	}

	void Timekeeper::stop()
	{
		endTimeObj = std::chrono::steady_clock::now();
	}

	void Timekeeper::recordEvent(const char * description)
	{
		auto m_seconds = std::chrono::duration_cast<std::chrono::milliseconds> (endTimeObj - startTimeObj);

		if (noOfrecord < max) {

			record[noOfrecord].message = description;
			record[noOfrecord].unitTime = "seconds";
			record[noOfrecord].durationTimeObj = m_seconds;

			noOfrecord++;
		}
	}

	void Timekeeper::report(std::ostream & os) const
	{
		os << "\nExecution Times:\n";
		for (int i = 0; i < noOfrecord; i++)
		{
			os << record[i].message << ' ' << setw(5)
				<< record[i].durationTimeObj.count() / 100000
				<< record[i].unitTime
				<< endl;
		}

	}


}