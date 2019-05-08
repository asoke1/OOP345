// Workshop 4 - Containers
// MessagePack.h
// Abiodun Oke
// 2019/02/07
#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H
#include <iostream>
#include "Message.h"

namespace sict
{
	class MessagePack
	{
		Message* m_msg;  // suboject 
		int m_noOfElement;

	

	public:
		MessagePack();
		MessagePack(Message** msg, int arraysize);
		~MessagePack();

		MessagePack(const MessagePack& obj);
		MessagePack& operator=(const MessagePack& obj);

		MessagePack(MessagePack&& obj);
		MessagePack& operator=(MessagePack&& obj);

		void display(std::ostream& os) const;
		size_t size() const;

	};

	std::ostream& operator<<(std::ostream& os, const MessagePack& obj);
}

#endif // !SICT_MESSAGEPACK_H
