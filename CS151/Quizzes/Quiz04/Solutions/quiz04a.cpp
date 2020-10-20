#include <iostream>
using namespace std;

int I2DP(int n)
{
	if(n < 0)
	{
		n *= -1;
	}

	if(n < 10 || n > 99)
	{
		return 0;
	}
	else if(n % 2 == 0)
	{
		return 2;
	}
	else if(n % 3 == 0)
	{
		return 3;
	}
	else if(n % 5 == 0)
	{
		return 5;
	}
	else if(n % 7 == 0)
	{
		return 7;
	}
	else 
	{
		return 1;
	}
}

int main()
{
	return 0;
}
