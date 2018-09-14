#include<iostream>
class Fraction{
  
   int m_num,m_deno;
  
public: 
   Fraction(int num = 0,int deno = 1):m_num(num),m_deno(deno){
   
      reduce();
   }
 
   void print(){
 
      std::cout<<m_num<<"/"<<m_deno<<"\n";
   }

   static int GCD(int x,int y){
   
      int min = x < y ? x : y;
      if(min==0)
         return 1;
      int max = x > y ? x : y;
      if(max%min==0)
         return min;
      
      return GCD(min,max-min);
   }
  
   void reduce(){
     
      int gcd = GCD(m_num,m_deno);    
  
      m_num  /= gcd;
      m_deno /= gcd;
   }

   friend Fraction operator*(const Fraction &f1,const Fraction &f2);
   friend Fraction operator*(int f1,const Fraction &f2);
   friend Fraction operator*(const Fraction &f2,int f1);
   friend std::ostream& operator<<(std::ostream &out ,const Fraction &f);
   friend std::istream& operator>>(std::istream &in ,Fraction &f);
};

Fraction operator*(const Fraction &f1,const Fraction &f2){

   return Fraction(f1.m_num*f2.m_num,f1.m_deno*f2.m_deno);
}

Fraction operator*(int f1,const Fraction &f2){ 

   return Fraction(f1*f2.m_num,f2.m_deno);
}

Fraction operator*(const Fraction &f2,int f1){

   return Fraction(f1*f2.m_num,f2.m_deno);
}

std::ostream& operator<<(std::ostream &out ,const Fraction &f){

   out<<f.m_num<<"/"<<f.m_deno;

return out;
}

std::istream& operator>>(std::istream &in ,Fraction &f){
 
   char c;   
  
   in>>f.m_num>>c>>f.m_deno;

   f.reduce();

return in;
}

int main(){

        Fraction f1;
	std::cout << "Enter fraction 1: \n";
	std::cin >> f1;
 
	Fraction f2;
	std::cout << "Enter fraction 2: \n";
	std::cin >> f2;
 
	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';
 
	return 0;
}
