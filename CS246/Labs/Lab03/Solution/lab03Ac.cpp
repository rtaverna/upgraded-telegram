template<typename T>
int PlaceTarget(T data[],int n,const T& target)
{
	for(int i = 0;i < n;i += 1)
	{
		if(target < data[i])
		{
			return i;
		}
	}
	return n;
}

int main()
{
	return 0;
}
