/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : ms2
* Date        : 2019-03-25
**********************************************************/

#include <vector>
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {

	size_t CustomerOrder::m_fieldWidth = 0;


	CustomerOrder::CustomerOrder() : m_ItemInfo{ nullptr }, m_cusName{ "" }, m_prodName{ "" }, m_noOfItem{ 0 }
	{
	}
	
	CustomerOrder::CustomerOrder(const std::string& field) : CustomerOrder() {
		Utilities utility;

		size_t delim_pos = field.find(utility.getDelimiter());
		m_cusName = field.substr(0, delim_pos);

		if (m_fieldWidth < utility.getFieldWidth())
			m_fieldWidth = utility.getFieldWidth();

		m_prodName = utility.extractToken(field, delim_pos);

		m_noOfItem = std::count(field.begin(), field.end(), utility.getDelimiter()) - 1;
		m_ItemInfo = new ItemInfo[m_noOfItem];

		if (m_noOfItem >= 1) {
			for (size_t i = 0; i < m_noOfItem; i++)
				m_ItemInfo[i].strName = utility.extractToken(field, delim_pos);
		}
		else {
			throw "***No items are found***";
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& obj) 
	{
		*this = std::move(obj);
	}

	CustomerOrder & CustomerOrder::operator=(CustomerOrder&& obj) {
		if (this != &obj) 
		{
			m_cusName = obj.m_cusName;
			m_prodName = obj.m_prodName;
			m_noOfItem = obj.m_noOfItem;
			m_ItemInfo = obj.m_ItemInfo;

			obj.m_ItemInfo = { nullptr };
		}
		return *this;
	}

	
	CustomerOrder::~CustomerOrder() 
	{
		delete[] m_ItemInfo;
		m_ItemInfo = { nullptr };
	}

	
	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) 
	{
		for (size_t i = 0; i < m_noOfItem; ++i) 
		{
			if (item.getName() == m_ItemInfo[i].strName) {
				if (item.getQuantity() == 0)
					os << " Unable to fill " << m_cusName << " [" << m_prodName << "][" << m_ItemInfo[i].strName << "][" << m_ItemInfo[i].strSeriaNum << "] out of stock" << std::endl;
				else
				{
					if (m_ItemInfo[i].strFilledStatus)
						os << " Unable to fill " << m_cusName << " [" << m_prodName << "][" << m_ItemInfo[i].strName << "][" << m_ItemInfo[i].strSeriaNum << "] already filled" << std::endl;
					else
					{
						m_ItemInfo[i].strSeriaNum = item.getSerialNumber();
						m_ItemInfo[i].strFilledStatus = true;
						item.operator--();
						os << " Filled " << m_cusName << " [" << m_prodName << "][" << m_ItemInfo[i].strName << "][" << m_ItemInfo[i].strSeriaNum << "]" << std::endl;
					}
				}
			}
		}
	}

	
	bool CustomerOrder::isFilled() const 
	{
		for (size_t i = 0; i < m_noOfItem; ++i)
			if (!m_ItemInfo[i].strFilledStatus)
				return false;
		return true;
	}

	
	bool CustomerOrder::isItemFilled(const std::string& item) const 
	{
		for (size_t i = 0; i < m_noOfItem; ++i) 
		{
			if (m_ItemInfo[i].strName == item) 
			{
				if (!m_ItemInfo->strFilledStatus)
					return false;
			}
		}
		return true;
	}

	
	std::string CustomerOrder::getNameProduct() const 
	{
		return std::string(m_cusName) + "[" + std::string(m_prodName) + "]";
	}

	
	void CustomerOrder::display(std::ostream & os, bool showDetail) const {
		os << std::left << std::setw(m_fieldWidth) << m_cusName << " [" << m_prodName << "]" << std::endl;
		if (!showDetail) {

			for (size_t i = 0; i < m_noOfItem; ++i) 
			{
				os << std::setfill(' ') 
					<< std::setw(m_fieldWidth + 1) 
					<< "    " << std::right 
					<< m_ItemInfo[i].strName << std::endl;
			}
		}
	}
}