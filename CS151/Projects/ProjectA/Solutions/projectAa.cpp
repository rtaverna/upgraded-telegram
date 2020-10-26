#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//calculating GCD 
int GCD(int m,int n)
{
	if(m < 0)
	{
		return GCD((-1 * m),n);
	}
	else if(n < 0)
	{
		return GCD(m,(-1 * n));
	}
	else if(n == 0)
	{
		return ((m == 0)?(1):(m));
	}
	else 
	{
		int r = m % n;
		return GCD(n,r);
	}
}

bool Addition(int op1[],int op2[],int res[])
{
	//zero denominator
	if(op1[1] == 0 || op2[1] == 0)
	{
		return false;
	}
	
	//resultant numerator 
	res[0] = op1[0] * op2[1] + op2[0] * op1[1];

	//resultant denominator
	res[1] = op1[1] * op2[1];

	int gcd = GCD(res[0],res[1]);

	res[0] /= gcd;
	res[1] /= gcd;
	return true;
}


bool Subtraction(int op1[],int op2[],int res[])
{
	//zero denominator
	if(op1[1] == 0 || op2[1] == 0)
	{
		return false;
	}
	
	//resultant numerator 
	res[0] = op1[0] * op2[1] - op2[0] * op1[1];

	//resultant denominator
	res[1] = op1[1] * op2[1];

	int gcd = GCD(res[0],res[1]);

	res[0] /= gcd;
	res[1] /= gcd;
	return true;
}


bool Multiplication(int op1[],int op2[],int res[])
{
	//zero denominator
	if(op1[1] == 0 || op2[1] == 0)
	{
		return false;
	}
	
	//resultant numerator 
	res[0] = op1[0] * op2[0];

	//resultant denominator
	res[1] = op1[1] * op2[1];

	int gcd = GCD(res[0],res[1]);

	res[0] /= gcd;
	res[1] /= gcd;
	return true;
}
	
	
bool Division(int op1[],int op2[],int res[])
{
	//zero denominator
	if(op1[1] == 0 || op2[1] == 0 || op2[0] == 0)
	{
		return false;
	}
	
	//resultant numerator 
	res[0] = op1[0] * op2[1];

	//resultant denominator
	res[1] = op1[1] * op2[0];

	int gcd = GCD(res[0],res[1]);

	res[0] /= gcd;
	res[1] /= gcd;
	return true;
}

void Calculator()
{
	int c, a[2], b[2], r[2];
	bool oc;

	cout << "Rational Number Calculator\n";
	cout << "1. Addition\n";
	cout << "2. Subtraction\n";
	cout << "3. Multiplication\n";
	cout << "4. Division\n\n";
	cout << "Enter choice: ";
	cin >> c;

	if(c >= 1 && c <= 4)
	{
		cout << "\nEnter the numerator for the first operand: ";
		cin >> a[0];
		cout << "Enter the denominator for the first operand: ";
		cin >> a[1];
		cout << "Enter the numerator for the second operand: ";
		cin >> b[0];
		cout << "Enter the denominator for the second operand: ";
		cin >> b[1];

		if(c == 1)
		{
			oc = Addition(a,b,r);
		}
		else if(c == 2)
		{
			oc = Subtraction(a,b,r);
		}
		else if(c == 3)
		{
			oc = Multiplication(a,b,r);
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
				r[0] *= -1;
				r[1] *= -1;
			}
			cout << "\n" << r[0] << "/" << r[1] << "\n";
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
