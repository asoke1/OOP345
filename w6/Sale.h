/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : 6
* Date        : 2019-03-10
**********************************************************/

#ifndef SICT_SALE_H
#define SICT_SALE_H

#include <vector>
#include "iProduct.h"



namespace sict
{
	class Sale
	{
		std::vector<iProduct*> iProdObj;
	public:
		Sale(const char* fileName);
		void display(std::ostream& os) const;
	};

}
#endif // !SICT_SALE_H
