#include <iostream>
#include <string>
#include "Node.h"

double Average(ds::sn::Node<double>* root)
{
	if(root == NULL)
	{
		return 0;
	}

	double sum = 0;
	int n = 0;

	for(ds::sn::Node<double>* t = root;t != NULL;t = t->link)
	{
		sum += t->data;
		n += 1;
	}
	return (sum / n);
}

int main()
{
	return 0;
}
