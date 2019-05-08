/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : 6
* Date        : 2019-03-10
**********************************************************/
#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include "iProduct.h"

namespace sict
{
	class Product : public iProduct
	{
		int m_prodNum;
		double m_price;
	public:
		Product();
		explicit Product(int productNumber, double price);
		double price() const;
		void display(std::ostream& os) const;

	};
	
	
	// Derive class
	class TaxableProduct : public Product
	{
		double m_isTax;
		enum taxType
		{
			HST,
			PST
		};

	public:
		TaxableProduct(int prodNumber, double price, char tax_status);
		double price() const override;
		void display(std::ostream& os) const override;


	};
	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);
}

#endif // !SICT_PRODUCT_H
