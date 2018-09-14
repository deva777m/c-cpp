#include<array>
#include<iostream>
#include<typeinfo>
int passarray(std::array<int,>arr)
{
   return arr.size();
}
int main()
{
   std::array<int,>arr1={1,2,3,4};
   std::cout<<passarray(arr1)<<"\n";
   std::cout<<typeid(arr1).name()<<"\n";
}

