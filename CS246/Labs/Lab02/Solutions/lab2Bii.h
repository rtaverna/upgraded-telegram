#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include "Shape.h"

class RightTriangle : public lb::Shape
{
	private:
	double sides[3]; 

	public:
	RightTriangle() 
	{
		sides[0] = 1;
		sides[1] = 1;
		sides[2] = sqrt(2);
	}

	RightTriangle(double o,double a)
	{
		sides[0] = o;
		sides[1] = a;
		sides[2] = sqrt((sides[0]*sides[0] + sides[1]*sides[1]));
	}

	RightTriangle(const RightTriangle& obj)
	{
		sides[0] = obj.sides[0];
		sides[1] = obj.sides[1];
		sides[2] = obj.sides[2];
	}

	RightTriangle& operator=(const RightTriangle& rhs)
	{
		if(this != &rhs)
		{
			sides[0] = rhs.sides[0];
			sides[1] = rhs.sides[1];
			sides[2] = rhs.sides[2];
		}
		return *this;
	}

	~RightTriangle() {}

	double Perimeter() const 
	{
		return sides[0] + sides[1] + sides[2];
	}

	double Area() const 
	{
		return 0.5 * sides[0] * sides[1];
	}

	std::string ToString() const 
	{
		std::stringstream out;
		
		out << std::setprecision(2) << std::fixed;
		out << "{" << sides[0] << "," << sides[1] << "," << sides[2] << "}";
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const RightTriangle& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
