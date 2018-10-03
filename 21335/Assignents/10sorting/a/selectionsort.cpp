#include<iostream>

void print(double *a, int length)
{
	for(int i = 0; i < length; ++i)
	{
		std::cout << a[i] << " ";
	}
	
	std::cout << "\n";
}

void swap(double &x, double &y)
{
	double temp = x;
	x = y;
	y = temp;
}

void selSort(double *a, int length)
{
	for(int i = 0; i <  length; ++i)
	{
		int k = i;
		
		for(int j = i + 1; j  < length; ++j)
		{
			if(a[j] < a[k])
			{
				k = j;
			}
		}
		
		swap(a[i], a[k]);
	}	
}

int main()
{
	double a[4] = {3,2,4,1};
	
	print(a,4);

	selSort(a,4);
	
	print(a,4);
return 0;
}
