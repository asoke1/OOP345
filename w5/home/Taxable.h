/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : 5 - Functions
* Date        : 2019-02-14
**********************************************************/
#ifndef  SICT_TAXABLE_H
#define SICT_TAXABLE_H

namespace sict
{
	class Taxable
	{
		float m_taxRate;

	public:

		// A one-argument constructor 
		Taxable(float prescribe)
		{
			m_taxRate = prescribe;
		}

		float operator()(float price)
		{
			return (1 + m_taxRate) * price;
		}
	};
}
#endif // ! SICT_TAXABLE_H
