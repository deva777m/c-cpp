#include<iostream>
int main()
{
   int a[3][3];
   for(int i=0;i<3;i++)
   { 
     for(int j=0;j<3;j++)
        std::cin>>a[i][j];
   }
    
   for(int i=0;i<3;i++)
   { 
     for(int j=0;j<3;j++)
        std::cout<<a[i][j];
   } 
}
