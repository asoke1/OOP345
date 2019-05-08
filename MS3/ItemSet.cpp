/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : ms1
* Date        : 2019-03-07
**********************************************************/


#include <iostream>
#include <iomanip>
#include <string>
#include "ItemSet.h"
#include "Utilities.h"


using namespace std;

namespace sict
{
	const unsigned int CODE_WIDTH = 5;
	const unsigned int QUAN_WIDTH = 3;
	unsigned int ItemSet::fieldwidth = 12;

	ItemSet::ItemSet(const std::string& src)
	{
		size_t next_pos = src.find(m_Utilit.getDelimiter());
		m_name = src.substr(0, next_pos);
		m_seriaNum = std::stoul(m_Utilit.extractToken(src, next_pos));
		m_qty = std::stoi(m_Utilit.extractToken(src, next_pos));
		m_desc = m_Utilit.extractToken(src, next_pos);


		if (m_Utilit.getFieldWidth() < m_name.length())
			m_Utilit.setFieldWidth(m_name.length());
	}


	const std::string & ItemSet::getName() const
	{
		return m_name;
	}

	const unsigned int ItemSet::getSerialNumber() const
	{
		return m_seriaNum;
	}

	const unsigned int ItemSet::getQuantity() const
	{
		return m_qty;
	}

	ItemSet & ItemSet::operator--()
	{
		if (m_qty > 0)
		{
			m_qty--;
			m_seriaNum++;
		}
		return *this;
	}

	void ItemSet::display(std::ostream & os, bool full) const
	{

		os << std::setw(fieldwidth) << std::setfill(' ')
			<< std::left << m_name << " "
			<< "[" << std::setw(CODE_WIDTH) << std::setfill('0') << std::right << m_seriaNum << "]";

		if (full)
		{
			os << " " << "Quantity " << std::setw(QUAN_WIDTH) << std::setfill(' ')
				<< std::left << m_qty << " Description: " << m_desc;
		}

		os << endl;



	}

}