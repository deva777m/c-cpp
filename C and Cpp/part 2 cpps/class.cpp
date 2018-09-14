#include<iostream>
int main()
{
  class IntPairs
  {
  public:
    int m_x1;
    int m_x2;
    
    void set(int x1,int x2)
    {
        m_x1=x1;
        m_x2=x2;
    }
    
    void print()
    {
       std::cout<<m_x1<<"\n"<<m_x2<<"\n";
    }
  };

  IntPairs p1;
  p1.set(3,4);
  
  IntPairs p2{2,2};
  p1.print();
  p2.print();
}  
      
