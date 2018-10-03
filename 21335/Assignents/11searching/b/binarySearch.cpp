#include<iostream>
#include<algorithm>

int binarySearch(int element, int *a, int l,  int r)	// 1 2 3 4 5
{
	if (r >= l) 
	{ 
		int mid = l + (r - l)/2; 

		if (a[mid] == element)   
	            return mid; 
  
  		if (a[mid] > element)  
			return binarySearch(element, a, l, mid-1); 
  
		return binarySearch(element, a, mid+1, r); 
	} 
	
return -1; 
}

int main()
{
	int *a = NULL;
	int length = 0, element = 0;
	
	std::cout << "Enter number of students\n:- ";
	std::cin >> length;
	
	a = new int[length];
	
	for(int i = 0; i < length; ++i)
	{
		std::cout << "Roll no :- ";
		std::cin >> a[i];
	}
	
	std::sort(a, a + length);	

	std::cout << "Enter element to be searched\n:- ";
	std::cin >> element;
	
	int index = binarySearch(element, a, 0, length - 1);
	
	if(index != -1)
		std::cout << "Found at location " << index + 1 << '\n';
	else
		std::cout << "Not found\n";

return 0;
}
