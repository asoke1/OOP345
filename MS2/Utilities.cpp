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
	char Utilities::m_delimiter = '\0';
	size_t Utilities::m_fieldWidth = { 0 };

	
	

	Utilities::Utilities()
	{
	}

	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos)
	{
		
		size_t next_delimiter_pos = str.find(m_delimiter, next_pos + 1);

		size_t word_length = (next_delimiter_pos - next_pos) - 1;	

		std::string token = str.substr(next_pos + 1, word_length);			
		next_pos = next_delimiter_pos;										
		return token;
		
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
		m_delimiter = { d };
	}
	void Utilities::setFieldWidth(size_t f)
	{
		m_fieldWidth = { f };
	}
}