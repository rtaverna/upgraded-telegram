#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Shape.h"

class Rectangle : public lb::Shape
{
	private:
	double sides[2]; //or double sides[4];

	public:
	Rectangle() 
	{
		sides[0] = 1;
		sides[1] = 1;
	}

	Rectangle(double l,double w)
	{
		sides[0] = l;
		sides[1] = w;
	}

	Rectangle(const Rectangle& obj)
	{
		sides[0] = obj.sides[0];
		sides[1] = obj.sides[1];
	}

	Rectangle& operator=(const Rectangle& rhs)
	{
		if(this != &rhs)
		{
			sides[0] = rhs.sides[0];
			sides[1] = rhs.sides[1];
		}
		return *this;
	}

	~Rectangle() {}

	double Perimeter() const 
	{
		return 2 * (sides[0] + sides[1]);
	}

	double Area() const 
	{
		return sides[0] * sides[1];
	}

	std::string ToString() const 
	{
		std::stringstream out;
		
		out << std::setprecision(2) << std::fixed;
		out << "{" << sides[0] << "," << sides[1] << "," << sides[0] << "," << sides[1] << "}";
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const Rectangle& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
