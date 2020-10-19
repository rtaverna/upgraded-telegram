#include <iostream>
#include <string>
using namespace std;

int RealRootsCount(double a,double b,double c)
{
	//find the dicriminant of the quadratic equation
	double d = b * b - 4 * a * c;

	if(d > 0) 
	{
		return 2;
	}
	else if(d < 0) 
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void TemperatureConverter(double& Temp,char From,char To)
{
	if((From == 'f' || From == 'F') && (To == 'c' || To == 'C'))
	{
		//fahrenheit to celsius C = (5/9)*(F - 32)
		Temp = (5.0 / 9.0) * (Temp - 32);
	}
	else if((From == 'c' || From == 'C') && (To == 'f' || To == 'F'))
	{
		//celsius to fahrenheit F = (9/5)*C + 32
		Temp = (9.0 / 5.0) * Temp + 32;
	}
}

double NonNegativeMean(double a,double b,double c,double d,double e)
{
	double s = 0.0;
	int n = 0;

	if(a >= 0)
	{
		s += a;
		n += 1;
	}
	
	if(b >= 0) 
	{
		s += b;
		n += 1;
	}

	if(c >= 0)
	{
		s += c;
		n += 1;
	}

	if(d >= 0)
	{
		s += d;
		n += 1;
	}
	
	if(e >= 0)
	{
		s += e;
		n += 1;
	}

	return (n == 0)?(0.0):(s / n);
}

int main()
{
	double a, b, c, d, e, t;
	char x, y;
 
	cout << "Enter the quadratic coefficient: ";
	cin >> a;

	cout << "Enter the linear coefficient: ";
	cin >> b;

	cout << "Enter the constant coefficient: ";
	cin >> c;

	cout << "The number of real roots of the equation " << a << "x^2 + " << b << "x + " << c << " = 0 is " << RealRootsCount(a,b,c) << "\n\n";

	cout << "Enter a temperature: ";
	cin >> t;
	
	cout << "Enter the first initial of its unit: ";
	cin >> x;

	cout << "Enter the first initial of the unit\nthat you want the temperature to be converted to: ";
	cin >> y;

	cout << t << " " << x << " converts to ";
	TemperatureConverter(t,x,y);
	cout << t << " " << y << "\n\n";
 
	cout << "Enter a number: ";
	cin >> a;

	cout << "Enter a number: ";
	cin >> b;

	cout << "Enter a number: ";
	cin >> c;
	
	cout << "Enter a number: ";
	cin >> d;

	cout << "Enter a number: ";
	cin >> e;

	cout << "The mean of the nonnegative values of the numbers " << a << ',' << b << ',' << c << ',' << d << ',' << e << " is ";
	cout << NonNegativeMean(a,b,c,d,e) << "\n";
 
	return 0;
}
