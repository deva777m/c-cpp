#include<iostream>
void prime1(int prime[5])
{
   prime[0]=11;
   prime[1]=7;
   prime[2]=5;
   prime[3]=3;
   prime[4]=2;
}
int main()
{
   int i;
   int prime[5]={2,3,5,7,11};
   for(i=0;i<=4;i++)
     std::cout<<prime[i]<<" ";
   prime1(prime);
   for(i=0;i<=4;i++)
     std::cout<<prime[i]<<" ";
   
}
