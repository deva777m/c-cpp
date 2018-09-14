#include<iostream>
class myint{

   int m_x;
   
public:

   myint(int x=10):m_x(x){}
   
   int get(){
  
      return m_x;
   }
   friend myint operator+(myint &m1,myint &m2);

};

myint operator+(myint &m1,myint &m2){

   return myint(m1.m_x+m2.m_x);
}

int main(){

   myint int1=20;
   myint int2=20;

   myint sum=int1+int2;
   
   std::cout<<sum.get()<<"\n";

return 0;
}

