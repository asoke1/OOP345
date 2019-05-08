// Workshop 3 - Templates
// List.h
// Abiodun Oke
// 2019/01/31

#ifndef SICT_LIST_H
#define SICT_LIST_H

namespace sict {

	template<typename T, int N>
	class List
	{
		T array[N];
		size_t arrNum = 0;

	public:
		List() // Default construct 
		{}

		// Return the number of element stored in the array
		size_t size() const
		{
			return arrNum;
		}

		// Return reference to the unmodifiable object at index of the array
		const T& operator[](size_t i) const
		{
			return array[i];
		}


		void operator+=(const T& t)
		{
			if (arrNum < N)
			{
				// appends a copy
				array[arrNum] = t;
				arrNum++;
			}
		}




	};

}

#endif


