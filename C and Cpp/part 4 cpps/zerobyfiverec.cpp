#include<iostream>
#include<cmath>  // 12034

int foo(int x,int i,int x2){  //12034
    
    int r;
    r=x%10;
    if(r==0)
       x2=x2+i;
    if(x==0)
       return x2-i;
    foo(x/10,i*10,x2);
}    

int main(){

   int x,x2;
   std::cin>>x;
   x2=x;
   int i=5;
   std::cout<<foo(x,i,x2)<<"\n";   
}
