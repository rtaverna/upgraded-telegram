#include <iostream>
#include <string>
#include "Node.h"

template<typename T>
void FrontAppend(ds::sn::Node<T>*& data,ds::sn::Node<T>* addon)
{
	if(data == NULL)
	{
		data = addon;
	}
	else if(addon != NULL)
	{
		ds::sn::Node<T>* t = addon;
	
		while(t->link != NULL)
		{
			t = t->link;
		}
		t->link = data;
		data = addon;
	}
}

bool LessThan(ds::mn::Node<bool>* op1,ds::mn::Node<bool>* op2)
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
	//greater than op2, hence, return false
	while(c1 > c2)
	{
		if(a->data)
		{
			return false;
		}
		c1 -= 1;
		a = a->next;
	}

	//if op2 has more digits than op1, get it to the 
	//same position; however, if a 1 is seen, op2 is
	//greater than op1, hence, return true
	while(c2 > c1)
	{
		if(b->data)
		{
			return true;
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
		if(!a->data && b->data)
		{
			return true;
		}
		else if(a->data && !b->data)
		{
			return false;
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
