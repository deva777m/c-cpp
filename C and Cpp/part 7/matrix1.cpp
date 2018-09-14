#include<iostream>

void printMatrix(int *a, int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{		
			std::cout << *(a + col * i + j) << " ";
		}
		
		std::cout << '\n';			
	}
}

int main()
{
	int row,col;  // for i rows and j columns
	
	std::cout << "Enter rows and columns :- \n";

	std::cin >> row >> col;
	
	int *a = new int [row * col];

	// In this approach we will assign the pointers sequentially even after change in rows.

	// but in this apprach we wont be able to refrence values using two subscripts since we have a single pointer.

	// check printed values.

	// both appraoches imp if we dont want fixed sizes for arrays.

	std::cout << "Enter elements\n";

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			std::cin >> *(a + col * i + j);
		}	
	}

	printMatrix(a,row,col);	

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			std::cout << (a + col * i + j) << " ";
		}
	
		std::cout << '\n';	
	}	

	delete[] a;

return 0;
}
