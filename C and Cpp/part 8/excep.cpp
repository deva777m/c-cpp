#include<iostream>

int main()
{
	int x;
	
	std::cin>>x;

	try
	{
		if(x < 0)
		{
			throw -1;
		}
		std::cout<<"Despacito\n";
	}	
	
return 0;
}
