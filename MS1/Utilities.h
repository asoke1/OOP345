#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

#include <string>
/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : ms1
* Date        : 2019-03-07
**********************************************************/

namespace sict
{
	class Utilities
	{
		
		size_t m_fieldWidth;
		static char m_delimiter;
		

	public:

		Utilities();
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		void setFieldWidth(size_t);



	};
}
#endif // !SICT_UTILITIES_H
