#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.h"

int MaximumDistance(ds::Array<int>& data)
{
	//Verify the minimum constraint  
	if(data.Length() <= 1)
	{
		return 0;
	}

	//Calculate the first adjacent (consecutive) distance and make 
	//it the first maximum value
	int d = (data[0] < data[1])?(data[1] - data[0]):(data[0] - data[1]);
	int mx = d;

	//Loop through the array to calculate the remaining adjacent distances
	//and compare them to the current maximum distance. 
	for(int i = 2;i < data.Length();i += 1)
	{
		d = (data[i] < data[i-1])?(data[i-1] - data[i]):(data[i] - data[i-1]);
		
		if(mx < d)
		{
			mx = d;
		}
	}
	//Return the maximum value
	return mx;
}

template <typename T>
bool Different(ds::Array<T>& ar1,ds::Array<T>& ar2)
{
	//Assign n the smaller of the two array lengths
	int n = (ar1.Length() <= ar2.Length())?(ar1.Length()):(ar2.Length());

	//Loop through the first n elements of both array and check if 
	//elements with the same index are equal.
	for(int i = 0;i < n;i += 1)
	{
		if(ar1[i] == ar2[i])
		{
			return false;
		}
	}
	//Return true if the loop terminates
	return true;
}

template <typename T>
void EndAppend(ds::Array<T>& data,ds::Array<T>& addon)
{
	//Assign the lengths of each array to their own varaible and 
	int n = data.Length();
	int m = addon.Length();

	//Copy the array data to a temporary array
	ds::Array<T> tmp = data;
	//Resize data to the sum of lengths of data and addon.
	data.Resize(n + m);

	//Copy the temporary array to data
	for(int i = 0;i < n;i += 1)
	{
		data[i] = tmp[i];
	}

	//Copy addon to data starting at the offset of n for data 
	for(int i = 0;i < m;i += 1)
	{
		data[n+i] = addon[i];
	}
}

/***************************************
Runtime Table 
cost	| time	| operation
========================================
1	| 1	| int i;
1	| 1	| int lc = 0;
1	| 1	| int rc = 0;
1	| 1	| const ln = r - p + 1;
1	| 1	| const rn = q - r;
1	| 1	| int L[ln];
1	| 1	| int R[rn];
1	| 1	| i = 0
1	| ln + 1| i < ln
1	| ln	| L[i] = a[p + i];
1 	| ln	| i += 1
1	| 1	| i = 0
1	| rn + 1| i < rn
1	| rn	| R[i] = a[r + i + 1];
1	| rn	| i += 1
1	| 1	| i = p
1	| ln + 1| lc < ln && rc < rn
1	| ln	| L[lc] <= R[rc]
1	| ln	| a[i] = R[rc];
1	| ln	| rc += 1;
1	| ln	| i += 1
1	| 1	| lc < ln
1	| rn + 1| rc < rn
1	| rn	| a[i] = L[lc];
1	| rn	| i += 1;
1	| rn	| lc += 1;
========================================
T(n) = 7n + ln + 15 
****************************************/
  
int main()
{
	return 0;
}
