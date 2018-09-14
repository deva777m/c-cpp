#include<iostream>
int main()
{
   int value = 5;
   const int *p = &value;
   std::cout<<*p;
   value =7;
   std::cout<<*p;
}
