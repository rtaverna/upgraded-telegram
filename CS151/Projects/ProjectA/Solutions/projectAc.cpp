#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void Addition(double op1[],double op2[],double res[])
{
	
	//resultant x component
	res[0] = op1[0] + op2[0];

	//resultant y component
	res[1] = op1[1] + op2[1];

	//resultant z component
	res[2] = op1[2] + op2[2];
}

void Subtraction(double op1[],double op2[],double res[])
{
	
	//resultant x component
	res[0] = op1[0] - op2[0];

	//resultant y component
	res[1] = op1[1] - op2[1];

	//resultant z component
	res[2] = op1[2] - op2[2];
}

double DotProduct(double op1[],double op2[])
{
	
	//resultant 
	double res = op1[0] * op2[0] + op1[1] + op2[1] + op1[2] * op2[2];
	return res;
}
	
void CrossProduct(double op1[],double op2[],double res[])
{
	
	//resultant x component
	res[0] = op1[1] * op2[2] - op1[2] * op2[1];

	//resultant y component
	res[1] = op1[2] * op2[0] - op1[0] * op2[2];

	//resultant z component
	res[2] = op1[0] * op2[1] - op1[1] * op2[0];
}

void Calculator()
{
	int c;
	double a[3], b[3], r[3], rc;
	bool oc;

	cout << "3D Vector Calculator\n";
	cout << "1. Addition\n";
	cout << "2. Subtraction\n";
	cout << "3. Dot Product\n";
	cout << "4. Cross Product\n\n";
	cout << "Enter choice: ";
	cin >> c;

	if(c >= 1 && c <= 4)
	{
		cout << "\nEnter the x component for the first operand: ";
		cin >> a[0];
		cout << "Enter the y component for the first operand: ";
		cin >> a[1];
		cout << "Enter the z component for the first operand: ";
		cin >> a[2];
		cout << "Enter the x component for the second operand: ";
		cin >> b[0];
		cout << "Enter the y component for the second operand: ";
		cin >> b[1];
		cout << "Enter the z component for the second operand: ";
		cin >> b[2];

		if(c == 1)
		{
			Addition(a,b,r);
		}
		else if(c == 2)
		{
			Subtraction(a,b,r);
		}
		else if(c == 3)
		{
			oc = true;
			rc = DotProduct(a,b);
		}
		else 
		{
			CrossProduct(a,b,r);
		}
		cout << fixed << setprecision(1);

		if(oc)
		{
			cout << "\n" << rc << "\n";
		}
		else
		{
			cout << "\n<" << r[0] << ',' << r[1] << ',' << r[2] << ">\n";
		}
	}
	else 
	{
		cout << "\nInvalid Operation\n";
	}
}	

int main()
{
	Calculator();
	return 0;
}
