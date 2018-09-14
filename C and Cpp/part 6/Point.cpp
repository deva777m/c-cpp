#include<iostream>
#include<cmath>

class Point{

   int m_x;
   int m_y;
   int m_z;


public:

   Point(int x=0,int y=0,int z=0)
          :m_x(x),m_y(y),m_z(z){}
   
   void print(){

      std::cout<<"Point("<<m_x<<","<<m_y<<","<<m_z<<")\n";
   }
   
   friend int distanceFrom(const Point &p1,const Point &p2);
  
};

int distanceFrom(const Point &p1,const Point &p2){
  
      return sqrt((p1.m_x-p2.m_x)*(p1.m_x-p2.m_x)+(p1.m_y-p2.m_y)*(p1.m_y-p2.m_y)+(p1.m_z-p2.m_z)*(p1.m_z-p2.m_z));
}
