#include<iostream>
#include<cassert>
int main()
{
   int x=4;
   int &ref = x;
   std::cout<<&ref<<&x<<"\n";
}
   
