
/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : 5 - Functions
* Date        : 2019-02-14
**********************************************************/

#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H
#include <iostream>


namespace sict
{
	template<typename T>
	class KVList
	{
		T* m_list;
		int m_noOfElement;
		int m_currentElement;

	public:
		// A default constructor 
		KVList() : m_list{ nullptr }, m_noOfElement{ 0 }, m_currentElement{ 0 } {}

		// A single-constructor
		KVList(int n)
		{

			if (n > 0)
			{
				m_noOfElement = { n };
				m_currentElement = { 0 };
				m_list = new T[n];

			}
			else {
				
				throw "Error: Number of elements must be a positive number";
			}
		}

		// a move constructor. 
		KVList(KVList&& src)
		{
			if (this != &src)
			{
				m_noOfElement = src.m_noOfElement;
				m_currentElement = src.m_currentElement;
				m_list = src.m_list;

				src.m_noOfElement = { 0 };
				src.m_currentElement = { 0 };
				src.m_list = { nullptr };
			}

		}

		// A Destructor
		~KVList() { delete[] m_list; }

		// 
	
		const T& operator[](size_t i) const
		{
			if (i > m_noOfElement)
			{
				throw "Error: The index passed to the subscripting operator is out-of-bounds";

			}
			return m_list[i];
		}

		template<typename F>
		void display(std::ostream& os, F f) const
		{
			for (int i = 0; i < m_noOfElement; i++)
			{
				m_list[i].display(os, f);
			}
		}

		void push_back(const T& t)
		{
			if (m_currentElement + 1 <= m_noOfElement)
				m_list[m_currentElement] = t;

			++m_currentElement;
		}


	};
}

#endif 