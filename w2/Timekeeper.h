// Workshop 2 - Copy and Move Semantics
// Timekeeper.h
// Abiodun Oke
// 2019/01/24


#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H
#include <iostream>
#include <chrono>

namespace sict {
	const int max = 10;
	class Timekeeper {
	
		int noOfrecord{0};
		std::chrono::steady_clock::time_point startTimeObj;
		std::chrono::steady_clock::time_point endTimeObj;
		struct
		{
			std::chrono::steady_clock::duration durationTimeObj;
			const char* message;
			const char* unitTime;
		} record[max];
	
	public:
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char* description);
		void report(std::ostream& os) const;

	};

}
#endif // !SICT_TIMEKEEPER_H
