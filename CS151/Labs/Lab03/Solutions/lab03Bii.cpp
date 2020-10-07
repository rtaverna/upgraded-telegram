#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool OddMult7(int n)
{
	return (((n * n) % 2 == 1) && ((n * n) % 7 == 0));
}

double Quadratic(double a,double b,double c,double x)
{
	double r = a * x * x + b * x + c;
	return r;
}

int NumberSwap(double& a,double& b,double& c)
{
	a = a + b;
	b = a - b;
	a = a - b;
	a = a + c;
	c = a - c;
	a = a - c;
}

int main()
{
	int n;
	double a, b, c, x;
	
	cout << "Enter a number: ";
	cin >> n;
	
	cout << boolalpha;
	cout << "It is " << OddMult7(n) << " that " << n << " is an odd multiple of 7\n";

	cout << "\nEnter a number for a: ";
	cin >> a;
	
	cout << "Enter a number for b: ";
	cin >> b;

	cout << "Enter a number for c: ";
	cin >> c;

	cout << "Enter a number for x: ";
	cin >> x;

	cout << "ax^2 + bx + c = " << Quadratic(a,b,c,x) << "\n";

	cout << "\nEnter a number: ";
	cin >> a;

	cout << "Enter a number: ";
	cin >> b;
	
	cout << "Enter a number: ";
	cin >> c;
	
	cout << "(a,b,c) = (" << a << ',' << b << ',' << c << ")\n(a,b,c) = (";

	NumberSwap(a,b,c);
	
	cout << a << ',' << b << ',' << c << ")\n";

	return 0;
}
