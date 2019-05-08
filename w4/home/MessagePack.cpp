// Workshop 4 - Containers
// MessagePack.cpp
// Abiodun Oke
// 2019/02/07
#include <iostream>
#include <utility>
#include "Message.h"
#include "MessagePack.h"

using namespace std;
namespace sict
{



	MessagePack::MessagePack() : m_msg{ nullptr }, m_noOfElement{0}
	{
		
	}

	// A two - argument constructor
	MessagePack::MessagePack(Message** msg, int arraysize)
	{
	

		if (arraysize > 0 && msg != nullptr)
		{
			m_noOfElement = { 0 };
			m_msg = new Message[arraysize];

			for (int i = 0; i < arraysize; ++i)
			{
				if (!(*msg[i]).empty())
					m_msg[i] = *msg[i];
				else
					m_msg[i] = Message();

					m_noOfElement++;
			}

			//take out element that shouldnt in the class
			for (int i = 0; i < m_noOfElement; ++i)
			{
				if (m_msg[i].empty())
				{
					for (int j = i; j < m_noOfElement - 1; ++j)
						m_msg[j] = m_msg[j + 1];

					m_msg[m_noOfElement - 1] = Message();
	
				}
			}
			m_noOfElement--;
		}
	}

	// Destructor 
	MessagePack::~MessagePack()
	{
		delete[] m_msg;
		m_msg = nullptr;
	}

	// Copy constructor 
	MessagePack::MessagePack(const MessagePack& obj)
	{
		*this = obj;
	}

	// Copy Assignment operator
	MessagePack& MessagePack::operator=(const MessagePack& obj)
	{
		if (this != &obj)
		{
			delete[] m_msg;
			m_noOfElement = obj.m_noOfElement;

			for (int i = 0; i < m_noOfElement; i++)
			{
				m_msg[i] = obj.m_msg[i];
			}
		}

		return *this;
	}

	// Move Constructor
	MessagePack::MessagePack(MessagePack&& obj)
	{	
		*this = std::move(obj);
	}

	

	// Move Assignment operator
	MessagePack & MessagePack::operator=(MessagePack && obj)
	{
		if (this != &obj)
		{
			m_msg = obj.m_msg;
			m_noOfElement = obj.m_noOfElement;

			obj.m_msg = { nullptr };
			obj.m_noOfElement = { 0 };
		}
		return *this;
	}

	// Display: a query that inserts into the output stream os
	void MessagePack::display(std::ostream & os) const
	{
		for (int i = 0; i < m_noOfElement; i++)
		{
			if (!m_msg[i].empty())
				m_msg[i].display(os);
		}
	}

	size_t MessagePack::size() const
	{
		return size_t(m_noOfElement);
	}

	std::ostream& operator<<(std::ostream& os, const MessagePack & obj)
	{
		obj.display(os);
		return os;
	}

}