#ifndef SET_H
#define SET_H

#include <iostream>
#include <sstream>
#include <string>

template <class T>
class Set
{
	private:
	T data[100];
	int size;

	public:
	Set() : size(0) 
	{
		for(int i = 0;i < 100;i += 1)
		{
			data[i] = T();
		}
	}

	Set(const Set<T>& obj)
	{
		size = obj.size;
		
		for(int i = 0;i < 100;i += 1)
		{
			data[i] = obj.data[i];
		}
	}

	Set<T>& operator=(const Set<T>& rhs)
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

	~Set() {}

	void Add(const T& item)
	{
		if(!IsFull() && !Contains(item))
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

	friend std::ostream& operator<<(std::ostream& out,const Set<T>& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
