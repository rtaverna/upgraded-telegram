#include <iostream>
#include <string>
using namespace std;

/*****************************************************************
* Section I
******************************************************************
a.
	cout << ((x == y)?("Same"):("Different"));
b.
	int Value(int a[],int b,char& c,char& d);
c.
	void SwapIfGreater(double& a,double& b)
	{
		if(a > b)
		{
			double t = a;
			a = b;
			b = t;
		}
	}
d.
	string roman[5] = {"I","II","III","IV","V"};
e.
	int t = (2 * n + 1) * (2 * n + 1) * (2 * n + 1);
******************************************************************/


/*****************************************************************
* Section II
******************************************************************/
string MonthName(int n)
{
	string names[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	
	if(n >= 1 && n <= 12)
	{
		return names[n-1];
	}
	else
	{
		return "";
	}
} 


/****************************************************************
* Section III
*****************************************************************
Let 	L1 = a < b 
	L2 = b < c
	L3 = c < d
	L4 = a < b
	L5 = b < c
	L6 = a < b
   				
01. a := 2, b := 21, c := 9, d := 17
02. L1 := true				
03. a := 23				
04. b := 2				
05. a := 21				
06. L2 := true				
07. b := 11				
08. c := 2				
09. b := 9				
10. L3 := true				
11. c := 19				
12. d := -17				
13. c := -36				
14. L4 := false				
15. L5 := false				
16. L6 := false				
*****************************************************************/

/*****************************************************************
* Section IV
******************************************************************
Corrections:
06 void set(int a[],int i,int v)
14 a[i] = v + 1;
18 int swapmid(int a[],int i,int j)
21 a[i] = a[j];
34 int c = 0;
44 else if(!v[2])
54 int nms[10], t;
60 set(vls,3);
69 cin >> nms[7];
73 }
