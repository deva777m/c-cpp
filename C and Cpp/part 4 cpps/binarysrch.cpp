#include<iostream> // 5,2,1,4,9
#include<array>

void swap(int &x, int &y) {

	int temp;
	
	temp=x;
	x=y;
	y=temp;
}

void ascend(std::array<int,100>&a) {

	int n = sizeof(a)/sizeof(a[0]);

	for(int i=0;i<n;i++) {

		int k=i;

		for(int j=i+1;j<n;j++) {

			
			if(a[k]>a[j])
				k=j;
			
		}
		swap(a[i],a[k]);

	}
}

int binarysrch(const std::array<int,100>&a,int x,int min,int max) { // 1,2,3,3,5,6,7,8,9

	while(max>=min) {

		int centre = (min+max)/2;
	
		if(a[centre] > x) {
			
			max = centre-1;
		}

		else if(a[centre] < x) {
		
			min =centre+1;
		}

		else if(a[centre] == x) {

			return centre;
		}
		
	}
return -1;

}

int main() {

	std::array<int,100>a;
	int n,x;

	std::cin>>n;

	for(int i=0;i<n;i++)
		std::cin>>a[i];

	ascend(a,n);

	for(int i=0;i<n;i++) {

		std::cout<<a[i]<<" ";

	} 

	std::cout<<"\nEnter number to be searched : ";
	std::cin>>x;

	int index = binarysrch(a,x,0,n-1);

	if(index==-1) {
	
		std::cout<<"Not found"<<'\n';

	}

	else {

	std::cout<<"Position of x is "<<index+1<<'\n';

	}

return 0;

}
