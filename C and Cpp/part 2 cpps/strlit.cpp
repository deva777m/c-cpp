#include<iostream>
#include<typeinfo>
int main()
{
  int s=3;
  int *p=&s;
  std::cout<<*p;
  p=nullptr;
  std::cout<<p<<typeid(p).name();
}
