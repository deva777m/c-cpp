#include<iostream>
#include<cmath>  // 12030

int foo(int x){  //12030
    int t;
    if(x==0)
       return 0;
    t=x%10;
    if(t==0)
       t=5;
       int s=foo(x/10)*10+t;
       return s;
}
int main(){

   int x,x2;
   std::cin>>x;
   std::cout<<foo(x)<<"\n";   
}
