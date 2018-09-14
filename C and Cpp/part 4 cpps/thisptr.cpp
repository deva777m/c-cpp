#include<iostream>
class Foo
{
   int m_x;
public:
   int x=10010;
   
   Foo():m_x{0}{}
   
   Foo& set(int value)
   {
      m_x = value;
      return *this;
   }
   
   Foo* print()
   {
      std::cout<<m_x<<"\n";
      return this;      
   }
     
};

int main()
{
  Foo bar;
  std::cout<<bar.x<<"\n";
  
  Foo goo;
  goo.set(5).set(6).set(7);
  goo.print();
  
  Foo *p=goo.print();
  std::cout<<p->print();
  
  
}
