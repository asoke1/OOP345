

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

/**********************************************************
* Name        : Abiodun Oke
* Student ID  : 117180166
* Section     : SDD
* Seneca email: asoke@myseneca.ca
* Workshop	  : ms1
* Date        : 2019-03-07
**********************************************************/

namespace sict
{
	class ItemSet
	{
		char m_delim;
		std::string m_name = "";
		std::string m_desc;
		unsigned int m_seriaNum{ 0u };
		unsigned int m_qty{ 0u };
		static unsigned int fieldwidth;

	public:
		ItemSet(const std::string&);

		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full) const;

	};

}

#endif // !SICT_ITEMSET_H
