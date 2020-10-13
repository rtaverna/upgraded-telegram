#include <iostream>
#include "lab2Biii.h"

int main()
{
	Ellipse a, b(3,4);

	std::cout << a.Perimeter() << " " << b.Perimeter() << "\n";
	std::cout << a.Area() << " " << b.Area() << "\n";
	std::cout << a  << " " << b << "\n";

	return 0;
}
