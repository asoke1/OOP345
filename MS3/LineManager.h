#ifndef SICT_LINEMANAGER_H
#define SICT_LINEMANAGER_H

#include <iostream>
#include <vector>
#include "Station.h"


namespace sict
{
	class LineManager
	{
		std::vector<Station*> m_Station;
		std::vector<CustomerOrder> m_CustomerOrder;
		std::vector<size_t> m_Indexes;
		int startingVal{ 0 };
		std::ostream* myOutputStream;
		size_t secondVal{ 0 };

	public:

		LineManager(std::vector<Station*>& StationAddr, std::vector<size_t>& sizetobj, std::vector<CustomerOrder>& CustObj, int index, std::ostream& os);
		void display(std::ostream& os) const;
		bool run(std::ostream& os);
	};
}

#endif // !SICT_LINEMANAGER_H
