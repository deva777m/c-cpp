#include<iostream>

bool linearSearch( int element, int *a, int length )
{
	for(int i = 0; i < length; ++i)
	{
		if(a[i] == element)
			return true;
	}
	
return false;
}


bool sentinalSearch( int element, int *a, int length )
{
	int i = 0;

	int last = a[length - 1];

	a[length - 1] = element;

	while( a[i] != element )
		i++;
	
	a[length - 1] = last;
	
	if( i < length - 1 || element == a[length - 1])
		return true;

return false;
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
	
	std::cout << "Enter element to be searched\n:- ";
	std::cin >> element;
	
	if(linearSearch(element, a, length))
		std::cout << "Found\n";
	else
		std::cout << "Not found\n";
		
	if(sentinalSearch(element, a, length))
		std::cout << "Found\n";
	else
		std::cout << "Not found\n";
return 0;
}
