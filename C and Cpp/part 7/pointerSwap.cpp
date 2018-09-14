#include<iostream>

void swap(int **a, int **b)
{
	int *temp = nullptr;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int x = 3;
	int y = 4;

	int *ptr1 = &x;
	int *ptr2 = &y;

	std::cout << *ptr1 << " " << *ptr2 <<'\n';	

	swap(&ptr1, &ptr2);

	std::cout << *ptr1 << " " << *ptr2 <<'\n';	
}
