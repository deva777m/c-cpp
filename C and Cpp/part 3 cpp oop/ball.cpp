#include<iostream>
class Ball
{
  std::string m_color="black";
  int m_radius=10;
  
public:
  Ball()
  {
  }
  
  Ball(std::string color,int radius)
      :m_color{color},m_radius{radius}
  {
  }
  
  Ball(std::string color)
      :m_color{color}
  {
  }

  Ball(int radius)
      :m_radius{radius}
  {
  }
 
  void print()
  {
    std::cout<<"Color: "<<m_color<<" radius: "<<m_radius<<"\n";
  }
};

int main()
{
   Ball def;
   def.print();
    
   Ball blue("blue"); 
   blue.print();

   Ball twenty(20);
   twenty.print();
   
   Ball blueTwenty("blue",20);
   blueTwenty.print();

return 0;   
}
   
