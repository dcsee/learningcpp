#pragma once
#include <vector>
class Interview
{
public:
	Interview();
	~Interview();

	//const int * is a pointer to const ints. so CONST is applied to whatever is directly to the right of it. Read as "const int" *
	//int * const is a CONST POINTER to ints. So the pointer can't change, but the ints it's pointing to can. Read as "int *" const.
	//const int * const is a const pointer to a const int. Read as "const int" "* const"
	static int smallestInRotatedSortedArray(std::vector<int> array);
	
	static void sortMapByKey();
};
