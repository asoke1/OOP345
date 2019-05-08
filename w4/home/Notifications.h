// Workshop 4 - Containers
// Notifications
// Abiodun Oke
// 2019/02/07
#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H
#include <iostream>
#include "Message.h"


namespace sict
{

	class Notifications
	{
		const Message** pArrAddress;
		int m_maxNoAddress;
		int m_currentAddress;

	public:
		Notifications();
		Notifications(int);
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;

		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		


	};

	std::ostream& operator<<(std::ostream& os, Notifications& obj);

}

#endif
