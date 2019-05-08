/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : ms2
* Date        : 2019-03-25
**********************************************************/

#ifndef SICT_CUSTOMER_ORDER_H
#define SICT_CUSTOMER_ORDER_H

#include <iostream>
#include <string>
#include <memory>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {

	class CustomerOrder {

		struct ItemInfo
		{
			std::string strName;
			int strSeriaNum;
			bool strFilledStatus;
			ItemInfo() : strName{ "" }, strSeriaNum{ 0 }, strFilledStatus{ false } {}
		};

		ItemInfo* m_ItemInfo;
		std::string m_cusName;
		std::string m_prodName;
		size_t m_noOfItem;
		static size_t m_fieldWidth;

	public:
		CustomerOrder();
		explicit CustomerOrder(const std::string&);

		CustomerOrder(const CustomerOrder&) = delete;
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&);
		CustomerOrder& operator=(CustomerOrder&&);
		~CustomerOrder();

		void fillItem(ItemSet&, std::ostream&);
		bool isFilled() const;
		bool isItemFilled(const std::string&) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false) const;
	};
}

#endif // !_SICT_CUSTOMER_ORDER_H
