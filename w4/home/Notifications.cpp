// Workshop 4 - Containers
// Notifications.cpp
// Abiodun Oke
// 2019/02/07
#include <iostream>
#include <utility>
#include "Notifications.h"

namespace sict
{
	// Default constructor
	Notifications::Notifications() : pArrAddress{ nullptr }, m_maxNoAddress{ 0 }, m_currentAddress{ 0 }
	{
	}

	// Copy constructor
	Notifications::Notifications(const Notifications& obj)
	{
		*this = obj;
	}

	// Copy Assignment Operator
	Notifications& Notifications::operator=(const Notifications& obj)
	{

		if (this != &obj)
		{

			delete[] pArrAddress;

			m_maxNoAddress = obj.m_maxNoAddress;
			m_currentAddress = obj.m_currentAddress;

			for (int i = 0; i < obj.m_currentAddress; i++)
				pArrAddress[i] = obj.pArrAddress[i];
		}
		return *this;
	}

	// Move constructor
	Notifications::Notifications(Notifications&& obj)
	{
		*this = std::move(obj);
	}

	// Move Assignment Operator
	Notifications& Notifications::operator=(Notifications&& obj)
	{

		if (this != &obj)
		{

			pArrAddress = obj.pArrAddress;
			m_maxNoAddress = obj.m_maxNoAddress;
			m_currentAddress = obj.m_currentAddress;

			obj.pArrAddress = { nullptr };
			obj.m_maxNoAddress = { 0 };
			obj.m_currentAddress = { 0 };
		}
		return *this;
	}
	
	// one-argument constructor
	Notifications::Notifications(int src)
	{
		if (src > 0)
		{
			pArrAddress = new const Message*[src];
			m_maxNoAddress = src;
			m_currentAddress = { 0 };
		}
		else
			*this = Notifications();
	}


	Notifications& Notifications::operator+=(const Message& msg)
	{
		bool open = m_currentAddress < m_maxNoAddress;

		if (!msg.empty() && open)
		{
			pArrAddress[m_currentAddress] = &msg;
			++m_currentAddress;
		}

		return *this;
	}


	Notifications& Notifications::operator-=(const Message& msg)
	{
		for (int i = 0; i < m_currentAddress; i++)
		{
			bool found = pArrAddress[i] == &msg;

			if (found)
			{
				pArrAddress[i] = { nullptr };

				
				for (int x = i; x < m_currentAddress - 1; ++x)
					pArrAddress[x] = pArrAddress[x + 1];

				pArrAddress[m_currentAddress - 1] = { nullptr };
			}
		}

		m_currentAddress--;

		return *this;
	}
	void Notifications::display(std::ostream& os) const
	{
		for (int i = 0; i < m_currentAddress; i++)
			(*pArrAddress[i]).display(os);
	}
	size_t Notifications::size() const
	{
		return m_currentAddress;
	}
	std::ostream & operator<<(std::ostream & os, Notifications & n)
	{
		n.display(os);
		return os;
	}
}
