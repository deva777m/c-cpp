#include<iostream>

const char* rec(int x, int y)
{		
	//int temp = x;	
	
	if(x == 100)
	{
		return "Sex";
	}

	rec(y + x, y);
}

int main()
{
	int x = 10;

	std::cout << rec(x,x) <<'\n';
}
