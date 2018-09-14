#include<iostream>

using namespace std;

int find(int (&m)[5000],int n) // 3,1,0
{
    int k=0;
    	for(int j=k+1;j<n;j++)
        {
			if(m[j]>m[k])
				k=j;
        }
    
return k;
}

void shift(char (&b)[5000],const int &n)  // accd ,abcd 
{
    int i=0;
    int t=b[0];
    for(i=0;i<n-1;i++)
    {
        b[i]=b[i+1];
    }
    b[n-1]=t;
        
}
int main()
{
   char a[5000],b[5000],c[5000];
   int n;
   cin>>n;
   int p=n-1;
   int max[5000],count=0;

   for(int i=0;i<n;i++)
      cin>>a[i];
   for(int i=0;i<n;i++)
      cin>>b[i];
   for(int j=0;j<n;j++)
   { 
        int count=0;
   		for(int i=0;i<n;i++)
   		{
   			if(a[i]==b[i])
        	   count++;
   		}
        max[j]=count;
    	shift(b,n);
   }
   int index = find(max,n);
   cout<<index;
}

