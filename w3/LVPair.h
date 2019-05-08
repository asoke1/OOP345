// Workshop 3 - Templates
// LVPair.h
// Abiodun Oke
// 2019/01/31

#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
#include <iostream>
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

		void display(std::ostream& os) const
		{
			os << varLabel << " : " << varValue << endl;
		}


	};

	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair)
	{
		pair.display(os);
		return os;
	}

}

#endif // !SICT_LVPAIR_H


