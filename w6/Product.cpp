/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : 6
* Date        : 2019-03-10
**********************************************************/
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Product.h"
extern int FW;

using namespace std;

namespace sict
{
	Product::Product() : m_prodNum{0}, m_price{0.0}
	{
	}
	Product::Product(int productNumber, double price)
	{
		m_prodNum = productNumber;
		m_price = price;
	}

	double Product::price() const
	{
		return m_price;
	}

	void Product::display(std::ostream & os) const
	{
		int fieldWidth = FW;
		os << std::setw(fieldWidth)
			<< m_prodNum 
			<< std::setw(fieldWidth)
			<< m_price;
	}

	iProduct* readRecord(std::ifstream& file)
	{
		iProduct* product = nullptr;

		std::string line = {};
		int product_number = { 0 };
		double price = { 0 };
		char tax = { '\0' };

		while (std::getline(file, line, '\n'))
		{
			size_t count = std::count(line.begin(), line.end(), ' ');		// count how many spaces in line
			std::stringstream stream(line);
			if (count == 2)
			{
				stream >> product_number >> price >> tax;
				product = new TaxableProduct(product_number, price, tax);
				break;
			}
			else
			{
				stream >> product_number >> price;
				product = new Product(product_number, price);
				break;
			}
		}

		return product;
		
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p)
	{
		p.display(os);
		return os;
	}

	TaxableProduct::TaxableProduct(int prodNumber, double price, char t_status)
		: Product(prodNumber, price), m_isTax(t_status == 'H' ? 0.13 : 0.08)
	{
		
	}

	double TaxableProduct::price() const
	{
		return Product::price() * (1 + m_isTax);
	}
	
	void TaxableProduct::display(std::ostream & os) const
	{
		Product::display(os);

		if (m_isTax == 0.13) 
			os << " HST";
		else
			os << " PST";
	}

}
