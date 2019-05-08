// Workshop 3 - Templates
// List.h
// Abiodun Oke
// 2019/02/05

#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
#include <iostream>
//#include "List.h"
using namespace std;
namespace sict {

	template<typename L, typename V>

	class LVPair
	{
		L varLabel;
		V varValue;

	public:
		LVPair() {}

		LVPair(const L& label, const V& value)
		{
			varLabel = label;
			varValue = value;
		}

		virtual void display(std::ostream& os) const
		{
			os << varLabel << " : " << varValue << endl;
		}

		const L& getLabel() const {
			return varLabel;
		}

		const V& getValue() const {
			return varValue;
		}

	};



	// Drived class
	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V>
	{
		static V initValSum;
		static size_t minWidth;

	public:
		SummableLVPair() {}

		SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v)
		{
			if (minWidth < label.size())
			{
				minWidth = label.size();
			}
		}

		static const V& getInitialValue()
		{
			return initValSum;
		}
	

		V sum(const L& label, const V& sum) const
		{
			return (label == LVPair<L, V>::getLabel()) ? LVPair<L, V>::getValue() + sum : sum;

		}

		void display(std::ostream& os) const
		{
			os.setf(std::ios::left);
			os.width(minWidth);
			LVPair<L, V>::display(os);
			os.unsetf(std::ios::left);
		}
	};

	
	template<typename L, typename V>
	size_t SummableLVPair<L, V>::minWidth = 0u;

	
	template<>
	int SummableLVPair<std::string, int>::initValSum = 0;

	
	template<>
	std::string SummableLVPair<std::string, std::string>::initValSum = "";

	
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& s1, const std::string& s2) const
	{
		return (s1 == LVPair<std::string, std::string>::getLabel()) ? (s2 + " " + LVPair<std::string, std::string>::getValue()) : s2;
	}

	// Helper function 
	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair)
	{
		pair.display(os);
		return os;
	};

}

#endif // !SICT_LVPAIR_H
