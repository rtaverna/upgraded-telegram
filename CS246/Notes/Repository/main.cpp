#include <iostream>
#include "Array.h"

int main()
{
	ds::Array<int> a(31);
	int b = 1;

	for(int i = 0;i < a.Length();i += 1, b *= 2)
	{
		a[i] = b;
	} 

	std::cout << a << "\n";
	return 0;
} 
