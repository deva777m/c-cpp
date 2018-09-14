#include<array>
#include<vector>
#include"saumitra.h"

void selsort(std::array<int,A_LENGTH>&a,int min, int max) {
	
	int n = max - min + 1;

	for(int i=0;i<n-1;i++) 
	{
		int k=i;

		for(int j=i+1;j<n;j++) 
		{
			if(a[k]>a[j])
			{
				k=j;
			}
		}
		
		if(i == k)
		{
			continue;
		}

		swap(a[i],a[k]);

	}
}


void selsort(std::array<double,A_LENGTH>&a,int min, int max) {

	int n = max - min + 1;

	for(int i=0;i<n-1;i++) {

		int k=i;
		
		for(int j=i+1;j<n;j++) 
		{
			if(a[k]>a[j])
			{
				k=j;
			}
		}
		
		if(i == k)
		{
			continue;
		}

		swap(a[i],a[k]);
	}
}


void selsort(std::vector<int>&a) {

	int n = a.size();

	for(int i=0;i<n-1;i++) {

		int k=i;
		
		for(int j=i+1;j<n;j++) 
		{
			if(a[k]>a[j])
			{
				k=j;
			}
		}
		
		if(i == k)
		{
			continue;
		}

		swap(a[i],a[k]);
	}
}

void selsort(std::vector<double>&a) {

	int n = a.size();

	for(int i=0;i<n-1;i++) {

		int k=i;
		
		for(int j=i+1;j<n;j++) 
		{
			if(a[k]>a[j])
			{
				k=j;
			}
		}

		if(i == k)
		{
			continue;
		}

		swap(a[i],a[k]);
	}
}

void selsort(int *a,int min, int max) {

	int n = max - min + 1;

	for(int i=0;i<n-1;i++) {

		int k=i;

		for(int j=i+1;j<n;j++) 
		{
			if(a[k]>a[j])
			{
				k=j;
			}
		}
		
		if(i == k)
		{
			continue;
		}

		swap(a[i],a[k]);
	}
}

void selsort(char *a,int min, int max) {

	int n = max - min + 1;

	for(int i=0;i<n-1;i++) {

		int k=i;

		for(int j=i+1;j<n;j++) 
		{
			if(a[k]>a[j])
			{
				k=j;
			}
		}
		
		if(i == k)
		{
			continue;
		}

		swap(a[i],a[k]);
	}
}


void selsort(double *a,int min, int max) {

	int n = max - min + 1;

	for(int i=0;i<n-1;i++) {

		int k=i;

		for(int j=i+1;j<n;j++) 
		{
			if(a[k]>a[j])
			{
				k=j;
			}
		}

		if(i == k)
		{
			continue;
		}

		swap(a[i],a[k]);
	}
}


void selsort(const char *(*a),int min ,int max)
{
	int n = max - min + 1;
	
	for(int i=0;i<n-1;i++) 
	{
		int k=i;

		for(int j=i+1;j<n;j++) 
		{
			int l = 0;
			
			while(true) 
			{
				if(a[k][l] > a[j][l])
				{
					k=j;

					break;
				}
				else if(a[k][l] == a[j][l])
				{
					if((a[k][l] == '\0') && (a[j][l] == '\0'))
					{
						break;
					}
					l++;
				}
				else
				{
					break;
				}
			}			
		}
		
		if(i == k)
		{
			continue;
		}

		swap(a,i,k);
	}
}

