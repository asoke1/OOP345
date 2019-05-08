#include "Station.h"

namespace sict
{
	Station::Station(std::string& src)
	{
		this->m_ItemSet = new ItemSet(src);
	}

	void Station::display(std::ostream &os) const
	{
		m_ItemSet->display(os, m_ItemSet->getQuantity());
	}


	void Station::fill(std::ostream& os)
	{

		if (m_CustomerOrder.size() > 0)
		{
			if (!m_CustomerOrder[m_CustomerOrder.size()]->isFilled())
			{
				m_CustomerOrder[m_CustomerOrder.size()]->fillItem(*m_ItemSet, os);
			}
		}
	}

	const std::string& Station::getName() const
	{
		
		return m_ItemSet->getName();
	}

	bool Station::hasAnOrderToRelease() const
	{
		if (m_CustomerOrder[0]->isFilled() || m_ItemSet->getQuantity() == 0)
		{
			return true;
		}
		else if (m_CustomerOrder.size() == 0) // if no orders in queue
		{
			return false;
		}
		else
		{
			return false;
		}
	}

	Station& Station::operator--()
	{
		m_ItemSet->operator--();
		return *this;
	}

	Station& Station::operator+=(CustomerOrder &&order)
	{
		m_CustomerOrder.push_back(&order);
		return *this;
	}

	bool Station::pop(CustomerOrder &ready)
	{
		m_CustomerOrder.pop_front();

		if (ready.isFilled())
		{
			return true;
		}
		else if (m_CustomerOrder.size() == 0)
		{
			return false;
		}
		else
		{
			return false;
		}

	}

	void Station::validate(std::ostream& os) const
	{

		os << " getItem(): " << m_ItemSet->getName()
			<< "\n getSerialNumber(): " << m_ItemSet->getSerialNumber()
			<< "\n getQuantity(): " << m_ItemSet->getQuantity()
			<< std::endl;
	}
}