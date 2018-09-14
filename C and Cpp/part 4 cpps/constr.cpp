#include<iostream>
class Football
{
   std::string m_name="Bhava";
   int m_age=19;
public:
   Football(std::string name):Football("Lavdya",50)
   {
       std::cout<<"Hi\n";
   }

   Football( std::string u_name,int age):Football("Badya")
   {
       std::cout<<"Nigga\n";
   }
   
   void print()
   {
      std::cout<<m_name<<"\n";
   }
};
int main()
{
   Football me("Messi");
return 0;
}
