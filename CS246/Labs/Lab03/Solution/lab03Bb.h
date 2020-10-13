#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <sstream>
#include <string>

template <class T>
class Bag
{
	private:
	T data[100];
	int size;

	public:
	Bag() : size(0) 
	{
		for(int i = 0;i < 100;i += 1)
		{
			data[i] = T();
		}
	}

	Bag(const Bag<T>& obj)
	{
		size = obj.size;
		
		for(int i = 0;i < 100;i += 1)
		{
			data[i] = obj.data[i];
		}
	}

	Bag<T>& operator=(const Bag<T>& rhs)
	{
		if(this != &rhs)
		{
			size = rhs.size;
			
			for(int i = 0;i < 100;i += 1)
			{
				data[i] = rhs.data[i];
			}
		}
		return *this;
	}

	~Bag() {}

	void Add(const T& item)
	{
		if(!IsFull())
		{
			data[size] = item;
			size += 1;
		}
	}

	void Remove(const T& item)
	{
		if(!IsEmpty())
		{
			int idx = 0;
			
			while(idx < size && data[idx] != item)
			{
				idx += 1;
			}

			if(idx < size)
			{
				size -= 1;
				
				for(int i = idx;i < size;i += 1)
				{
					data[i] = data[i+1];
				}
			}
		}
	}

	bool IsFull() const 
	{
		return size == 100;
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	int Count() const 
	{
		return size;
	}

	bool Contains(const T& item) const 
	{
		for(int i = 0;i < size;i += 1)
		{
			if(data[i] == item)
			{
				return true;
			}
		}
		return false;
	}

	std::string ToString() const 
	{
		std::stringstream out;
		out << "{";

		for(int i = 0;i < size;i += 1)
		{
			out << data[i];

			if(i + 1 < size)
			{
				out << ",";
			}
		}
		out << "}";
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const Bag<T>& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
