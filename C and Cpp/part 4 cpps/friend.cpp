#include<iostream>
class foo
{
  int m_x;
  
public:
  
  foo(int x=10):m_x(x){}

  int getx(){return m_x;} 
   
};

void print(foo &goo)
{
  std::cout<<goo.getx()<<"\n";
}

int main()
{
   foo goo;
   print(goo);
}   
