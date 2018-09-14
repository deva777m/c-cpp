#include<iostream>
int main()
{
   int length;                        // 3,5,2,1,4,8                       
   std::cin>>length;
   int a[length];
   for(int i=0;i<length;i++)
      std::cin>>a[i];
   int k=0;
   for(int j=k+1;j<length;j++)
   {  
     if(a[k]>a[j])
     {  
        k=j;
     }
   }
std::cout<<"Smallest is "<<a[k]<<"\n";
   
}
