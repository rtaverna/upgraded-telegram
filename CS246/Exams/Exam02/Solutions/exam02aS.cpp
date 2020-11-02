#include <iostream>
#include <string>
#include "Node.h"
#include "Array.h"
#include "Vector.h"
#include "Stack.h"
#include <cstdlib>
#include <ctime>

int MaximumCount(ds::Array<double>& data)
{
	if(data.Length() == 0) 
	{
		return 0;
	}

	double mx = data[0];
	int cnt = 1;

	for(int i = 1;i < data.Length();i += 1)
	{
		if(data[i] > mx)
		{
			mx = data[i];
			cnt = 1;
		}
		else if(data[i] == mx)
		{
			cnt += 1;
		}
	}
	return cnt;
}

template <typename T>
void BubbleSort(ds::mn::Node<T>* root)
{
	ds::mn::Node<T>* t = root;
	
	while(t->next != NULL)
	{
		t = t->next;
	}

	for(;t != NULL;t = t->prev)
	{
		for(ds::mn::Node<T>* s = root;s != t;s = s->next)
		{
			if(s->data > s->next->data)
			{
				T a = s->data;
				s->data = s->next->data;
				s->next->data = a;
			}
		}
	}
}

bool ValidEnclosure(std::string word)
{
	ds::sn::Stack<char> s;

	for(int i = 0;word[i] != '\0';i += 1)
	{
		if(word[i] == '(' || word[i] == '[')
		{
			s.Push(word[i]);
		}
		else if(word[i] == ')')
		{
			if(s.IsEmpty() || s.Top() != '(')
			{
				return false;
			}
			s.Pop();
		}
		else if(word[i] == ']')
		{
			if(s.IsEmpty() || s.Top() != '[')
			{
				return false;
			}
			s.Pop();
		}
		else
		{
			return false;
		}
	}
	return s.IsEmpty();
}

template<typename T>
bool IsSet(ds::Array<T>& data)
{
	int n = data.Length();
	for(int i = 0;i < n;i += 1)
	{
		for(int j = i + 1;j < n;j += 1)
		{
			if(data[i] == data[j])
			{
				return false;
			}
		}
	}
	return true;
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
	std::string s;

	for(int i = 0;i < 20;i += 1)
	{
		d[i] = ((rand() % 9) + 1.0);
		ds::mn::Insert(r,r,(rand() % 100) + 1);
	}

	std::cout << d << "\n";
	Print(r);
	BubbleSort(r);
	Print(r);

	std::cout << "\n" << MaximumCount(d) << "\n";
	std::cout << std::boolalpha;
	std::cout << IsSet(d) << "\n";	

	std::cout << "Enter a string: ";
	std::cin >> s;

	std::cout << ValidEnclosure(s) << "\n";
	return 0;
}
