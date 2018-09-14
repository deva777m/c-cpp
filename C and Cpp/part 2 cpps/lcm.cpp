#include<iostream>
int greater(int x,int y)
{
   if(x>y)
     return x;
   else
     return y;
}

int smaller(int x,int y)
{
   if(x<y)
     return x;
   else
     return y;
}

int main()
{
   int x,y,num1=0;
   std::cin>>x;
   std::cin>>y;
   int small=smaller(x,y);
   int big=greater(x,y);
   for(int i=0;i<small;i++)
   {
     num1=num1+big;
     for(int j=0,num2=0;j<big;j++)
     {
       num2=num2+small;
       if(num1==num2)
       {
         std::cout<<"LCM is "<<num1<<"\n";
         return 0;
       }
     }
     
   }

}
