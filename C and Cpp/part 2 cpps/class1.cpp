#include<iostream>
class Point3d
{
   double m_x;
   double m_y;
   double m_z;
 public:
   
   void setValues(double x,double y,double z)
   {
      m_x=x;
      m_y=y;
      m_z=z;
   }
   
   void printValues()
   {
      std::cout<<"<"<<m_x<<","<<m_y<<","<<m_z<<">"<<"\n";
   }
   
   bool isEqual(const Point3d &d)
   {
    /* Instead of this:

      if((m_x==d.m_x)&&(m_y==d.m_y)&&(m_z==d.m_z))
        return true;
      else
        return false;
   */
      return ((m_x==d.m_x)&&(m_y==d.m_y)&&(m_z==d.m_z));
   }
};   

int main()
{
  Point3d point1;
  point1.setValues(1.0,2.0,3.0);
  
  Point3d point2;
  point2.setValues(1.0,4.0,3.0);

  if(point1.isEqual(point2))
    std::cout<<"Equal"<<"\n";
  else
    std::cout<<"Unequal"<<"\n";
    
}
