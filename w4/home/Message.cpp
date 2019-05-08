// Workshop 4 - Containers
// Message.cpp
// Abiodun Oke
// 2019/02/07

#include <iostream>
#include <string>
#include "Message.h"

using namespace std;

namespace sict {

	Message::Message()
	{
		userName.clear();
		m_reply.clear();
		m_tweet.clear();
		
	}

	Message::Message(const std::string& str)
	{
		std::string userString;
		std::string tweetString;
		std::string replyString;

		size_t firstSpace = str.find_first_of(' ');
		size_t secondSpace = str.find(' ', str.find_first_of(' ') + 1);
		size_t at = str.find('@');

		if (str.find_first_of(' ') != std::string::npos)
		{

			userString = str.substr(0, firstSpace);

			this->userName = userString;

			if (str.find('@') != std::string::npos)
			{

				replyString = str.substr((at + 1), ((secondSpace - firstSpace) - 2));
				tweetString = str.substr(secondSpace + 1);

				this->m_reply = replyString;
				this->m_tweet = tweetString;
			}

			else
			{
				tweetString = str.substr(firstSpace + 1);

				this->m_tweet = tweetString;
				this->m_reply.clear();
			}

		}

	}

	bool Message::empty() const
	{

		//return (userName.empty() && m_reply.empty() && m_tweet.empty());
		return (m_tweet.size()) < 1 ? true : false;

	}


	void Message::display(std::ostream& os) const
	{
		if (!empty())
		{
			os << ">User  : " << userName << endl;
			if (!m_reply.empty())
			{
				os << " Reply : " << m_reply << endl;
			}

			os << " Tweet : " << m_tweet << endl;
		}
	}


}
