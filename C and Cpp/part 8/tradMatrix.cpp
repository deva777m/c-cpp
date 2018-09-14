#include<iostream>

void printMatrix(int (*a)[3],int r, int c)
{
	std::cout << "pointer ver called\n";

	std::cout << '\n';

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			std::cout << a[i][j] << " ";
		}	
			
		std::cout << '\n';
	}
}

void printRefMatrix(int (&a)[4][3],int r, int c)
{
	std::cout << "ref ver called\n";

	std::cout << '\n';

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			std::cout << a[i][j] << " ";
		}	
			
		std::cout << '\n';
	}
}

void printCopyMatrix(int a[4][3],int r, int c)
{
	std::cout << "copy ver called\n";

	std::cout << '\n';

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			std::cout << a[i][j] << " ";
		}	
			
		std::cout << '\n';
	}
}

int main()
{
	int a[4][3];   // a is multidimensional array of the type (*a)[3] that is it is a pointer pointing to array contaning 3 elements

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			std::cin >> a[i][j];
		}	
	}	

	printMatrix(a,4,3);

	printRefMatrix(a,4,3);

	printCopyMatrix(a,4,3);

return 0;
}

