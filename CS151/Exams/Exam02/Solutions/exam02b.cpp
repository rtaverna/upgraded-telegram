#include <iostream>
#include <string>
using namespace std;

/*****************************************************************
* Section I
******************************************************************
a.
	if(x < y)
	{
		cout << -1;
	}
	else if(x > y)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
b.
	int a = (3 * T(2100) + 6) * (3 * T(2100) + 6);
c.
	const int odd3s[6] = {3,9,15,21,27,33};
d.
	string PassFail(double grd)
	{
		return ((grd >= 65)?("Pass"):("Fail"));
	}
e.
	bool Valid(char a[],char b[],int& c,string d,string e,string& f);
******************************************************************/


/*****************************************************************
* Section II
******************************************************************/
string WeekDayName(int n)
{
	string names[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	
	if(n >= 1 && n <= 7)
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
Let 	L1 = a > b 
	L2 = b > c
	L3 = c > d
	L4 = a > b
	L5 = b > c
	L6 = a > b
   					
01. a := 37, b := 26, c := 45, d := 19	
02. L1 := true				
03. a := 63				 
04. b := 37				
05. a := 26				
06. L2 := false				
07. L3 := true				
08. c := 64				
09. d := -45				
10. c := -109				
11. L4 := false				
12. L5 := true				
13. b := -72				
14. c := 37				
15. b := -109				
16. L6 := true				
17. a := -64				
18. b := 45				
19. a := -109				
*****************************************************************/

/*****************************************************************
* Section IV
******************************************************************
Corretions:
12 else
20 int t = a[i];
26 void set(int a[],int p)
31 int mismatches(int x[],int y[],int i)
45 {
55 int vls[] = {6,4,8,27,12};
60 set(nms,3);
63 set(vls,4,mismatches(nms,vls,1));
68 cout << ((nms[8] > nms[9])?("odds"):("evens")) << "\n";
72 return 0;
