#include <iostream>
#include <string>
#include "Node.h"
#include "Array.h"
#include "Vector.h"
#include "Stack.h"
#include <cstdlib>
#include <ctime>

bool IsMVCSudoku(ds::Vector<int>& bd)
{
	if(bd.Length() != 81) 
	{
		return false;
	}
	
	bool ds[81], s;

	for(int i = 0;i < 9;i += 1)
	{
		for(int j = 0;j < 9;j += 1)
		{
			ds[9*i+j] = false;
		}
	}

	for(int i = 0;i < 9;i += 1)
	{
		for(int j = 0;j < 9;j += 1)
		{
			if(bd[9*i+j] < 1 || bd[9*i+j] > 9 || bd[9*j+i] < 1 || bd[9*j+i] > 9)
			{
				return false;
			}
			ds[9*i+(bd[9*i+j]-1)] = true;	
			ds[9*(bd[9*j+i]-1)+i] = true;
		} 
	}
	
	for(int i = 0;i < 9;i += 1)
	{
		s = true;
		
		for(int j = 0;j < 9;j += 1)
		{
			s = s && ds[9*i+j];
		}

		if(!s)
		{
			return false;
		}
	}
	
	return true;
}

template <typename T>
void SelectionSort(ds::mn::Node<T>* root)
{
	for(ds::mn::Node<T>* t = root;t != NULL;t = t->next)
	{
		ds::mn::Node<T>* m = t;
		
		for(ds::mn::Node<T>* j = t->next;j != NULL;j = j->next)
		{
			if(m->data > j->data)
			{
				m = j;
			}
		}

		if(m != t)
		{
			T a = t->data;
			t->data = m->data;
			m->data = a;
		}
	}
}

std::string AdjacentDuplicateRemoval(std::string str)
{
	ds::sn::Stack<char> s;
	std::string rstr = "";

	for(int i = 0;str[i] != '\0';i += 1)
	{
		if(s.IsEmpty() || s.Top() != str[i])
		{
			s.Push(str[i]);
		}
		else if(s.Top() == str[i])
		{
			s.Pop();
		}
	}
	
	while(!s.IsEmpty())
	{
		rstr = s.Top() + rstr;
		s.Pop();
	}
	return rstr;
}

template<typename T>
int NthOccurrence(ds::Array<T>& data,const T& value,int n)
{
	if(data.Length() == 0 || n <= 0)
	{
		return -1;
	}

	int sz = data.Length(), cnt = 0;

	for(int i = 0;i < sz;i += 1)
	{
		if(data[i] == value)
		{
			cnt += 1;
			
			if(cnt == n)
			{
				return i;
			}
		}
	}
	return -1;
}

template <typename T>
void Print(ds::mn::Node<T>* root)
{
	std::cout << "[";
	ds::mn::Node<T>* t = root;

	while(t != NULL)
	{
		std::cout << t->data;
		
		if(t->next != NULL)
		{
			std::cout << ",";
		}
		t = t->next;
	}
	std::cout << "]\n";
}

int main()
{
	srand(time(NULL));
	ds::mn::Node<int>* r = NULL;
	ds::Vector<int> b(81);
	ds::Array<int> a(20);
	int n, v, h[9] = {1,2,3,4,5,6,7,8,9},sht;
	std::string s;

	for(int i = 0;i < 20;i += 1)
	{
		a[i] = ((rand() % 10) + 1);
		ds::mn::Insert(r,r,(rand() % 100) + 1);
	}

	sht = 0;
	for(int i = 0;i < 9;i += 1)
	{
		for(int j = 0;j < 9;j += 1)
		{
			b[i*9+j] = h[(sht+j)%9];
		}
		sht += 1;
	}
		 
	for(int i = 0;i < 81;i += 1)
	{
		std::cout << b[i] << (((i + 1) % 9 == 0)?("\n"):(" "));
	}
			

	std::cout << std::boolalpha;	
	std::cout << IsMVCSudoku(b) << "\n";

	Print(r);
	SelectionSort(r);
	Print(r);
	
	std::cout << "Enter a string: ";
	std::cin >> s;

	std::cout << AdjacentDuplicateRemoval(s) << "\n";

	std::cout << a << "\n";
	std::cout << "Enter a value: ";
	std::cin >> v;
	std::cout << "Enter an integer: ";
	std::cin >> n;
	std::cout << NthOccurrence(a,v,n) << "\n";
	return 0;
}
