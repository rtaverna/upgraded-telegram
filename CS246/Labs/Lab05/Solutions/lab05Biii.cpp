#include <iostream>
#include <string>
#include "Node.h"

template<typename T>
void MidAppend(ds::sn::Node<T>*& data,ds::sn::Node<T>* addon)
{
	ds::sn::Node<T>* t = data;
	ds::sn::Node<T>* s = addon;
	int c = 0;

	while(t != NULL)
	{
		c += 1;
		t = t->link;
	}

	c /= 2;
	t = data;

	while(s->link != NULL)
	{
		s = s->link;
	}

	for(int i = 0;i < c;i += 1)
	{
		t = t->link;
	}
	
	s->link = t->link;
	t->link = s;
}

bool NotEqual(ds::mn::Node<bool>* op1,ds::mn::Node<bool>* op2)
{
	ds::mn::Node<bool>* a = op1, *b = op2;
	int c1 = 0, c2 = 0;

	//count the digits in op1
	while(a != NULL)
	{
		a = a->next;
		c1 += 1;
	}

	//count the digits in op2
	while(b != NULL)
	{
		b = b->next;
		c2 += 1;
	}
	
	a = op1;
	b = op2;
	
	//if op1 has more digits than op2, get it to the
	//same position; however, if a 1 is seen, op1 is
	//not equal to op2, hence return true
	while(c1 > c2)
	{
		if(a->data)
		{
			return true;
		}
		c1 -= 1;
		a = a->next;
	}

	//if op2 has more digits than op1, get it to the 
	//same position; however, if a 1 is seen, op2 is
	//not equal op1, hence, return true
	while(c2 > c1)
	{
		if(b->data)
		{
			return false;
		}
		c2 -= 1;
		b = b->next;
	}
		
	//check each digit of op1 and op2 in the same 
	//position. if the digit of op1 is 1 while the
	//digit of op2 is 0, then op1 is greater. if the 
	//digit of op2 is 1 while the digit of op1 is
	//0, then op2 is greater. if theay are the same
	//the next digit has to be checked.
	while(a != NULL && b != NULL)
	{
		if(a->data != b->data)
		{
			return true;
		}
		a = a->next;
		b = b->next;
	}
	//op1 is equal to op2, so return false
	return false;
}


int main()
{
	return 0;
}
