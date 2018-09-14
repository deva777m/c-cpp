#include<iostream>
#include"saumitra.h"

int main()
{
	int n,m;

	std::cin>>m;

	const char (*a)[m];

	for(int j=0;j<m;j++)
			std::cin>>a[j];

	selsort(a,0,n-1);
}
