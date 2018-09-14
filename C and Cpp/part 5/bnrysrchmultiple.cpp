#include<iostream>
#include"saumitra_algorithms.h"

int i=0;

void binarysearch(int (&a)[1000000],int (&b)[1000000],int x,int min,int max) 
{ 

	

	while(max>=min) 
	{

		int centre = (min+max)/2;
	
		if(a[centre] > x) 
		{
			
			max = centre-1;
		}

		else if(a[centre] < x) 
		{
		
			min =centre+1;
		}

		else if(a[centre] == x) 
		{

			b[i]=centre;
			i++;
		
			int j=1;
			for(;j<=centre;j++)
			{
				if(a[centre-j]==x)	
				{
					b[i]=centre-j;
						i++;
				}
		

				if(a[centre+j]==x) 
				{
					b[i]=centre+j;
						i++;
				}

				if((a[centre-j]!=x)&&(a[centre+j]!=x))
					return;
			
				
			}
			if((j-1)==centre)
			{
				return;
			}
		}
		
	}
	

return;

}

int main()
{

	int a[1000000],n,x;

	std::cout<<"Enter Length of Array : \n";

	std::cin>>n;

	for(int j=0;j<n;j++)
	{
		std::cin>>a[j];
	}

	selsort (a,n);

	std::cout<<"Sorted Array is : \n";

	for(int j=0;j<n;j++)
	{
		std::cout<<a[j]<<" ";
	}

	std::cout<<"\nEnter number to be searched\n";

	int b[1000000];

	std::cin>>x;

	binarysearch(a,b,x,0,n);

	if(i==0)
	{
		std::cout<<"Number not found\n";
		return 0;
	}	

	selsort(b,i);

	if(i==1)
	{
		std::cout<<"The position of the number "<<x<<" is : \n";
	}
	else
	{
		std::cout<<"The positions of the number "<<x<<" are : \n";
	}
		
	for(int j=0;j<i;j++)
	{
		std::cout<<b[j]+1<<" ";
	}
	
		std::cout<<'\n';
	
return 0;
}
