#include <iostream>
#include <string>
#include "Node.h"
#include "Array.h"
#include "Vector.h"
#include "Stack.h"
#include <cstdlib>
#include <ctime>

bool PossiblePairs(ds::Array<int>& a,ds::Array<int>& b,int n)
{
	if(a.Length() == 0 || b.Length() == 0) 
	{
		return false;
	}
	
	int an = a.Length(), bn = b.Length();
	bool found;

	for(int i = 1;i < an;i += 1)
	{
		found = false;

		for(int j = 0;j < bn;j += 1)
		{
			if((a[i] + b[j]) >= n)
			{
				found = true;
				break;
			}
		}
		if(!found) 
		{
			return false;
		}
	}
	return true;
}

template <typename T>
void InsertionSort(ds::mn::Node<T>* root)
{
	for(ds::mn::Node<T>* t = root;t != NULL;t = t->next)
	{
		ds::mn::Node<T>* j = t->next;
		
		while(j != NULL && j->prev != NULL && j->data < j->prev->data)
		{
			T a = j->data;
			j->data = j->prev->data;
			j->prev->data = a;
			j = j->prev;
		}
	}
}

bool ValidTriplet(std::string word)
{
	ds::sn::Stack<char> s;

	for(int i = 0;word[i] != '\0';i += 1)
	{
		if(word[i] == 'a' || word[i] == 'A')
		{
			if(s.IsEmpty())
			{
				s.Push('a');
			}
		}
		else if(word[i] == 'b' || word[i] == 'B')
		{
			if(!s.IsEmpty() && s.Top() == 'a')
			{
				s.Pop();
				s.Push('b');
			}
		}
		else if(word[i] == 'c' || word[i] == 'C')
		{
			if(!s.IsEmpty() && s.Top() == 'b')
			{
				return true;
			}
		}
	}
	return false;
}

int MinimumCount(ds::Array<double>& data)
{
	if(data.Length() == 0)
	{
		return 0;
	}

	int n = data.Length(), cnt = 1;
	double mn = data[0];

	for(int i = 1;i < n;i += 1)
	{
		if(data[i] < mn)
		{
			mn = data[i];
			cnt = 1;
		}
		else if(data[i] == mn)
		{
			cnt += 1;
		}
	}
	return cnt;
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
	ds::Array<double> d(20);
	ds::Array<int> a(20), b(20);
	int n;
	std::string s;

	for(int i = 0;i < 20;i += 1)
	{
		d[i] = ((rand() % 9) + 1.0);
		a[i] = ((rand() % 10) + 1);
		b[i] = ((rand() % 10) + 1);
		ds::mn::Insert(r,r,(rand() % 100) + 1);
	}

	std::cout << d << "\n";
	Print(r);
	InsertionSort(r);
	Print(r);

	std::cout << MinimumCount(d) << "\n";
	std::cout << std::boolalpha;	

	std::cout << "Enter a string: ";
	std::cin >> s;

	std::cout << ValidTriplet(s) << "\n";

	std::cout << a << "\n" << b << "\n";
	std::cout << "Enter an integer: ";
	std::cin >> n;
	std::cout << PossiblePairs(a,b,n) << "\n";
	return 0;
}
