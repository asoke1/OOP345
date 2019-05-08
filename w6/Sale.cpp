/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : 6
* Date        : 2019-03-10
**********************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Sale.h"
#include "Product.h"

using namespace std;

extern int FW;
namespace sict
{

	Sale::Sale(const char * fileName)
	{

		if (fileName != nullptr && fileName[0] != '\0')
		{
			std::string buffer;
			size_t count = { 0 };
			std::ifstream fs;

			fs.open(fileName);
			if (fs.is_open())
			{
				while (std::getline(fs, buffer))
					count++;
				fs.clear();
				fs.seekg(0, std::ios::beg);
				for (size_t i = 0; i < count; i++)
					iProdObj.push_back(readRecord(fs));
				fs.close();
			}
			else
				throw "File cannot be opened";
		}
		else
			throw "File does not exist";
	}


	void Sale::display(std::ostream & os) const
	{
		int field = FW;
		os << "\nProduct No" << std::setw(field) << "Cost" << ' ' << "Taxable" << std::endl;
		double total = { 0.0 };

		for (auto& i : iProdObj)
		{
			os << *i;
			os << std::fixed << std::setprecision(2);
			total += i->price();
			os << std::endl;
		}
		os << std::setw(field) << "Total" << std::setw(field) << total << std::endl;
	
	}
}