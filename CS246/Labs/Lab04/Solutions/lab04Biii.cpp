#include <iostream>
#include <string>
#include "Node.h"

template<typename T>
bool Equal(Node<T>* ar1,Node<T>* ar2)
{
	Node<T> *a = ar1, *b = ar2;
	
	while(a != NULL && b != NULL)
	{
		if(a->data != b->data)
		{
			return false;
		}
		a = a->link;
		b = b->link;
	}
	return ((a == NULL) && (b == NULL));
}

int main()
{
	return 0;
}
