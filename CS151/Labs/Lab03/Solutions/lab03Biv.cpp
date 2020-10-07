#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ProductOfFive(int n)
{
	return (n * (n + 1) * (n + 2) * (n + 3) * (n + 4));
}

void Swap(char& s,char& t,char& u)
{
	char r = s;
	s = t;
	t = u;
	u = r;
}

string CapitalI()
{
	string ll = "* * * * * * * *\n", sl = "    * * * *\n", r = "";
	r += ll + ll + ll;
	r += sl + sl + sl + sl;
	r += ll + ll + ll;
	return r;
}

int main()
{
	int n;
	char x, y, z;

	cout << "Enter a number: ";
	cin >> n;

	cout << "The product of the 5 consecutive numbers starting with " << n << " is " << ProductOfFive(n) << "\n";

	cout << "\nEnter a character: ";
	cin >> x;

	cout << "Enter a character: ";
	cin >> y;

	cout << "Enter a character: ";
	cin >> z;

	cout << "(x,y,z) = (" << x << ',' << y << ',' << z << ")\n(x,y,z) = (";
	
	Swap(x,y,z);

	cout << x << ',' << y << ',' << z << ")\n";
	
	cout << "\n" << CapitalI() << "\n";

	return 0;
}
