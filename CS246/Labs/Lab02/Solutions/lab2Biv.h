#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Shape.h"

class Parallelogram : public lb::Shape
{
	private:
	double sides[2]; //or double sides[4];

	public:
	Parallelogram() 
	{
		sides[0] = 1;
		sides[1] = 1;
	}

	Parallelogram(double l,double w)
	{
		sides[0] = l;
		sides[1] = w;
	}

	Parallelogram(const Parallelogram& obj)
	{
		sides[0] = obj.sides[0];
		sides[1] = obj.sides[1];
	}

	Parallelogram& operator=(const Parallelogram& rhs)
	{
		if(this != &rhs)
		{
			sides[0] = rhs.sides[0];
			sides[1] = rhs.sides[1];
		}
		return *this;
	}

	~Parallelogram() {}

	double Perimeter() const 
	{
		return 2 * (sides[0] + sides[1]);
	}

	double Area() const 
	{
		return 0.5 * sides[0] * sides[1];
	}

	std::string ToString() const 
	{
		std::stringstream out;
		
		out << std::setprecision(2) << std::fixed;
		out << "{" << sides[0] << "," << sides[1] << "," << sides[0] << "," << sides[1] << "}";
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const Parallelogram& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
