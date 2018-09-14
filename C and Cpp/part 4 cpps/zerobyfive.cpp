#include<iostream>
#include<cmath>  // 12034

int digits(int &n){
 
   int c;
     
   while(n){
      n=n/10;
      c++;
   }
return c;
}

int main(){

   int x,x1,x2,y,r;
   std::cin>>x;
   x1=x;
   x2=x;
   int digit=digits(x1);
      
   for(int i=5;i<5*(pow(10,digit));i=i*10)
   {
      r=x%10;
      if(r==0)
         x2=x2+i;
      y=x/10;
      x=y;
   }
   
   std::cout<<x2<<"\n";   
}
