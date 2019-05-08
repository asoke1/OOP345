/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : ms1
* Date        : 2019-03-07
**********************************************************/

#include <iostream>
#include <string>
#include "Utilities.h"

using namespace std;
namespace sict
{
	char Utilities::m_delimiter;
	Utilities::Utilities()
	{
		
		m_fieldWidth = 1;
	//m_delimiter = {};
		
	}
	
	const std::string Utilities::extractToken(const std::string & str, size_t& next_pos)
	{
		
		bool more = true;

		std::string ret = str.substr(next_pos);
		size_t pos = ret.find(m_delimiter);
		if (pos != std::string::npos) {
			ret = ret.substr(0, pos);
			next_pos += pos + 1;
			more = true;
		}
		else {
			more = false;
		}
		return ret;

		
	}
	const char Utilities::getDelimiter() const
	{
		return m_delimiter;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_fieldWidth;
	}
	void Utilities::setDelimiter(const char d)
	{
		m_delimiter = d;
	}
	void Utilities::setFieldWidth(size_t f)
	{
		m_fieldWidth = f;
	}
}