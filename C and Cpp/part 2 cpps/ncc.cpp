#include<iostream>
int max(int *a,int s)
{
  for(int i=0;i<s-1;i++)  // 1,2,3  2,1,3
  {  
    if(a[i]<=a[i+1])
      continue;
    else
      a[i+1]=a[i];
  }  
return a[s-1];
}

int min(int *a,int s)
{
  for(int i=0;i<s-1;i++)
  {  
    if(a[i]>=a[i+1])
      continue;
    else
      a[i+1]=a[i];
  }
  return a[s-1];
}

int main()
{
   int t;
   std::cin>>t;
   while(t--)
   {
     int size,s;
     std::cin>>size;
     s=size;
     int a[s];
     int b[s];
     for(int i=0;i<s;i++)
       std::cin>>a[i];
     for(int i=0;i<s;i++)
       b[i]=a[i];
     int max1=max(a,s);
     int min1=min(b,s);
     int diff=max1-min1;
     std::cout<<diff<<"\n";
   }
} 
