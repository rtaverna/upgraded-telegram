#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void Addition(double op1[],double op2[],double res[])
{
	
	//resultant real 
	res[0] = op1[0] + op2[0];

	//resultant imaginary
	res[1] = op1[1] + op2[1];
}

void Subtraction(double op1[],double op2[],double res[])
{
	
	//resultant real 
	res[0] = op1[0] - op2[0];

	//resultant imaginary
	res[1] = op1[1] - op2[1];
}



void Multiplication(double op1[],double op2[],double res[])
{
	
	//resultant real 
	res[0] = op1[0] * op2[0] - op1[1] * op2[1];

	//resultant imaginary
	res[1] = op1[0] * op2[1] + op1[1] * op2[0];
}

	
	
bool Division(double op1[],double op2[],double res[])
{
	//zero denominator
	if(op2[0] == 0 && op2[1] == 0)
	{
		return false;
	}
	
	//calculate product of conjugates of the denominator 
	double cp = op2[0] * op2[0] + op2[1] * op2[1];

	//resultant real
	res[0] = op1[0] * op2[0] + op1[1] * op2[1];

	//resultant imaginary
	res[1] = op1[1] * op2[0] - op1[0] * op2[1];

	res[0] /= cp;
	res[1] /= cp;
	return true;
}

void Calculator()
{
	int c;
	double a[2], b[2], r[2];
	bool oc = true, sgn;

	cout << "Complex Number Calculator\n";
	cout << "1. Addition\n";
	cout << "2. Subtraction\n";
	cout << "3. Multiplication\n";
	cout << "4. Division\n\n";
	cout << "Enter choice: ";
	cin >> c;

	if(c >= 1 && c <= 4)
	{
		cout << "\nEnter the real component for the first operand: ";
		cin >> a[0];
		cout << "Enter the imaginary component for the first operand: ";
		cin >> a[1];
		cout << "Enter the real component for the second operand: ";
		cin >> b[0];
		cout << "Enter the imaginary component for the second operand: ";
		cin >> b[1];

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
			Multiplication(a,b,r);
		}
		else 
		{
			oc = Division(a,b,r);
		}

		if(!oc)
		{	
			cout << "\nError: dividing by zero.\n";
		}
		else
		{
			if(r[1] < 0)
			{
				sgn = true;
				r[1] *= -1;
			}
			cout << fixed << setprecision(1);
			cout << "\n" << r[0] << ((sgn)?(" - "):(" + ")) << r[1] << "i\n";
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
