#include <iostream>

int binarysrch(const int (&a)[1000000],int x,int min,int max) { 

	std::vector<int>b;

	if(max<min) {

	return -1;
	
	}

	int centre = (min+max)/2;
	
	if(a[centre] > x) {
			
		binarysrch(a,x,min,centre-1);
	}

	else if(a[centre] < x) {
		
		binarysrch(a,x,centre+1,max);
	}

	else if(a[centre] == x) {

		return index;
	}
		
}

int main()
{
	int a[1000000]{1,3,6,9,14,15,20,50};
	int x;

	std::cin>>x;

	std::cout<<binarysrch(a,x,0,7);
	
return 0;
}
