#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H
/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : ms1
* Date        : 2019-03-07
**********************************************************/


// Workshop 8 - Smart Pointers
// Utilities.h
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include "List.h"
#include "Element.h"

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
}

#endif