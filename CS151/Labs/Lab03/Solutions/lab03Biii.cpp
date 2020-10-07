#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double Perimeter(double wh,double lh)
{
	return (2 * (wh + lh));
}

void  Distance(double a,double b,double& r)
{
	r = abs(b - a);
}

string Arrangements(char a,char b,char c)
{
	string ac = string(1,a), bc = string(1,b), cc = string(1,c), r = "";
	r = r + ac + bc + cc + " ";
	r = r + ac + cc + bc + " ";
	r = r + bc + ac + cc + " ";
	r = r + bc + cc + ac + " ";
	r = r + cc + ac + bc + " ";
	r = r + cc + bc + ac;
	return r;
}

int main()
{
	double a, b, c;
	char x, y, z;
	string r;

	cout << "Enter a width: ";
	cin >> a;

	cout << "Enter a length: ";
	cin >> b;

	cout << "The perimeter is " << Perimeter(a,b) << "\n";

	cout << "\nEnter a value: ";
	cin >> a;
	
	cout << "Enter a value: ";
	cin >> b;

	Distance(a,b,c);

	cout << "The distance between " << a << " and " << b << " is " << c << "\n";

	cout << "\nEnter a character: ";
	cin >> x;

	cout << "Enter a character: ";
	cin >> y;
	
	cout << "Enter a character: ";
	cin >> z;

	r = Arrangements(x,y,z);
	
	cout << "All arrangements of " << x << ',' << y << " and " << z << " are " << r << "\n";

	return 0;
}
