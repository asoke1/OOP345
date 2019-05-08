// Workshop 4 - Containers
// Message.cpp
// Abiodun Oke
// 2019/02/07

#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H
#include <string>

namespace sict {

	class Message
	{
		std::string userName;
		std::string m_reply;
		std::string m_tweet;

	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;

	};


}

#endif // ! SICT_MESSAGE_H

