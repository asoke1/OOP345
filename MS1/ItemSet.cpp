/**********************************************************
* Name        : Abiodun Oke
* Student ID  : 117180166
* Section     : SDD
* Seneca email: asoke@myseneca.ca
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
		
		
		Utilities m_Utilit;
		size_t next_pos = 0;
		if (!src.empty())
		{
			m_name = m_Utilit.extractToken(src, next_pos);

			if (fieldwidth < m_Utilit.getFieldWidth())
			{
				fieldwidth = (unsigned int)m_Utilit.getFieldWidth();
				
			}

			if (next_pos != std::string::npos)
			{
				std::string temp = m_Utilit.extractToken(src, next_pos);
				m_seriaNum = atoi(temp.c_str());
			}

			if (next_pos != std::string::npos)
			{
				std::string temp = m_Utilit.extractToken(src, next_pos);
				m_qty = atoi(temp.c_str());
			}

			if (next_pos != std::string::npos)
			{
				m_desc = m_Utilit.extractToken(src, next_pos);
			}
		}
		
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