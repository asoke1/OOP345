// Workshop 3 - Templates
// List.h
// Abiodun Oke
// 2019/02/05
//#pragma once
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


	// Derive class
	template <typename T, typename L, typename V, int N>
	class LVList : public List<T, N>
	{
	public:
		V accumulate(const L& label) const
		{
			List<T, N>& tmp = (List <T, N>&)*this;
			SummableLVPair<L, V> summable;
			V result = summable.getInitialValue();


			for (size_t i = 0; i < tmp.size(); i++)
			{

				if (label == tmp[i].getLabel())
				{
					result = tmp[i].sum(label, result);
				}
			}
			return result;
		}
	};


}
#endif


