#include<iostream>
#include<typeinfo>
int main()
{
  auto i=3.4;
  float j=4.5;
  float &ref=j;
  long int k=2.444;
  std::cout<<typeid(i).name()<<"\n"<<typeid(&ref).name()<<"\n";
  std::cout<<sizeof(i)<<"\n"<<sizeof(j)<<"\n"<<sizeof(k)<<"\n";
  std::cout<<&ref<<"\n";
  std::cout<<&j<<"\n";
  
}

