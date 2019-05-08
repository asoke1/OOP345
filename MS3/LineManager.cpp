#include "LineManager.h"

namespace sict
{
	LineManager::LineManager(std::vector<Station*>& StationAddr, std::vector<size_t>& sizetobj, std::vector<CustomerOrder>& CustObj, int index, std::ostream& os)
	{
		m_Station = StationAddr;
		m_CustomerOrder = std::move(CustObj);
		m_Indexes = sizetobj;
		startingVal = index;
		myOutputStream = &os;
		secondVal = m_Indexes.at(startingVal);
	}

	void LineManager::display(std::ostream& os) const
	{
		for (size_t index = 0; index < m_CustomerOrder.size(); index++)
		{
			if (!m_CustomerOrder[index].isFilled())
			{
				m_CustomerOrder[index].display(os);
			}
		}
	}

	bool LineManager::run(std::ostream& os)
	{
		
		try
		{
			for (size_t index = 0; index < m_Station.size(); index++)
			{
				if (!this->m_CustomerOrder[m_CustomerOrder.size()].isFilled())
				{
					m_Station[this->m_Indexes[index]]->operator+=(std::move(m_CustomerOrder[index]));
					m_Station[this->m_Indexes[index]]->fill(os);
				}
			}
			return true;
		}
		catch (...)
		{
			return false;
		}

	}
}