#ifndef SICT_STATION_H
#define SICT_STATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict
{
	class Station
	{
		std::deque<CustomerOrder*> m_CustomerOrder;
		ItemSet* m_ItemSet;

	public:

		Station(std::string& src);
		void display(std::ostream& os) const;
		void fill(std::ostream& os);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os) const;
	};
}

#endif // SICT_STATION_H