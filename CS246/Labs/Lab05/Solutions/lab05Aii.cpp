#include <iostream>
#include <string>
#include "Node.h"

double Minimum(ds::sn::Node<double>* root)
{
	if(root == NULL)
	{
		return 0;
	}

	double mn = root->data;

	for(ds::sn::Node<double>* t = root->link;t != NULL;t = t->link)
	{
		if(t->data < mn)
		{
			mn = t->data;
		}
	}
	return mn;
}

int main()
{
	return 0;
}
