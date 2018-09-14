#include<iostream>
int main()
{
   int length;                             
   std::cin>>length;
   int a[length];
   for(int i=0;i<length;i++)
      std::cin>>a[i];
   int k=0;
   for(int j=0;j<length;j++)
   {  
     if(a[k]>a[j])
     {  
        k=j;
        j=0;
        continue;
     }
   }
std::cout<<"Smallest is "<<a[k]<<"\n";
   
}
