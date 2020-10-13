#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.h"

double AverageDistance(ds::Array<int>& data)
{
	//Verify the minimum constraints  
	if(data.Length() == 0)
	{
		return 0;
	}
	else if(data.Length() == 1)
	{
		return data[0];
	}	
	
	//declare distance variable and initialize sm to 0
	int d;
	double sm = 0;

	//Loop through the array to calculate the adjacent distances and
	//add them to sm.  
	for(int i = 1;i < data.Length();i += 1)
	{
		d = (data[i] < data[i-1])?(data[i-1] - data[i]):(data[i] - data[i-1]);
		sm += d;
	}
	//Return the average of the distances which is sm divided 
	//by 1 less than the length of data
	return (sm / (data.Length() - 1)); 
}

template <typename T>
bool Equal(ds::Array<T>& ar1,ds::Array<T>& ar2)
{
	//Assign n the length of ar1 
	int n = ar1.Length();
	
	//Check if the lengths of ar1 and ar2 are the same
	if(ar1.Length() != ar2.Length())
	{
		return false;
	}

	//Loop through the elements of both array and check if 
	//elements with the same index are not equal.
	for(int i = 0;i < n;i += 1)
	{
		if(ar1[i] != ar2[i])
		{
			return false;
		}
	}
	//Return true if the loop terminates
	return true;
}

template <typename T>
void FrontAppend(ds::Array<T>& data,ds::Array<T>& addon)
{
	//Assign the lengths of each array to their own varaible and 
	int n = data.Length();
	int m = addon.Length();

	//Copy the array data to a temporary array
	ds::Array<T> tmp = data;
	//Resize data to the sum of lengths of data and addon.
	data.Resize(n + m);

	//Copy addon to data
	for(int i = 0;i < m;i += 1)
	{
		data[i] = addon[i];
	}

	//Copy the temporar array to data starting at the offset of 
	//m for data 
	for(int i = 0;i < n;i += 1)
	{
		data[m+i] = tmp[i];
	}
}

/*****************************************************
Runtime Table 
cost	| time	| operation
======================================================
1	| 1	| int o[n];
1	| 1	| int c[10];
1	| 1	| int i = 0
1	| 11	| i < 10
1	| 10	| c[i] = 0;
1	| 10	| i += 1
1	| 1	| int i = 0
1	| n + 1	| i < n
1	| n	| c[(a[i] / k) % 10] += 1
1	| n	| i += 1
1 	| 1	| int i = 1
1	| 10	| i < 10
1	| 9	| c[i] += c[i-1];
1	| 9	| i += 1
1	| 1	| int i = n - 1
1	| n + 1	| i >= 0
1	| n	| o[c[(a[i] / k) % 10] - 1] = a[i];
1	| n	| c[(a[i]  k) % 10)] -= 1;
1	| n	| i -= 1
1	| 1	| int i = 0
1	| n + 1	| i < n
1	| n	| a[i] = o[i];
1	| n	| i += 1
======================================================
T(n) = 10n + 69  
******************************************************/
  
int main()
{
	return 0;
}
