#include <iostream>
#include <string>
using namespace std;

void CapLock(char& c)
{
	if(c >= 'a' && c <= 'z') 
	{
		c -= 32;
	}
	else if(c >= 'A' && c <= 'Z') 
	{
		c += 32;
	}
}

int DaysOfAMonth(int mn,int yr)
{
	if((mn >= 1 && mn <= 12) && yr > 0)
	{
		if(mn == 4 || mn == 6 || mn == 9 || mn == 11)
		{
			return 30;
		}
		else if(mn == 2)
		{
			return (yr % 4 == 0 && (yr % 100 != 0 || yr % 400 == 0))?(29):(28);
		}
		else
		{
			return 31;
		}
	}
	else
	{
		return 0;
	}
}

double Median(double a,double b,double c,double d)
{
	double o, p, q, r;

	//o < p
	if(a < b) 
	{
		o = a;
		p = b;
	}
	else
	{
		o = b;
		p = a;
	}

	//q < r
	if(c < d)
	{
		q = c;
		r = d;
	}
	else 
	{
		q = d;
		r = c;
	}

	//q either second or third
	if(o > q)
	{
		q = o;
	}

	//r either second or third
	if(p < r)
	{
		r = p;
	}

	return (q + r) / 2; 
}

int main()
{
	char c;
	int month, year;
	double a1, a2, a3, a4;
 
	cout << "Enter a character: ";
	cin >> c;

	cout << "The cap lock of " << c << " is ";
	CapLock(c);
	cout << c << "\n\n";

	cout << "Enter a month as a number: ";
	cin >> month;

	cout << "Enter a year: ";
	cin >> year;

	cout << "There are " << DaysOfAMonth(month,year) << " days in " << month << "/" << year << "\n\n";
 
	cout << "Enter a number: ";
	cin >> a1;

	cout << "Enter a number: ";
	cin >> a2;

	cout << "Enter a number: ";
	cin >> a3;
	
	cout << "Enter a number: ";
	cin >> a4;

	cout << "The median of the numbers " << a1 << ',' << a2 << ',' << a3 << ',' << a4 << " is ";
	cout << Median(a1,a2,a3,a4) << "\n";
 
	return 0;
}
