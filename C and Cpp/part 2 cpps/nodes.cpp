#include<iostream>
int eo(int &p)  //even odd 
{
   if(p%2==0)
      return 2;
   else
      return 1;
}  

int main()
{
   int n;  //n = sides
   int i;
   int sel[2]{1,2};
   std::cout<<"Sel 0 for poly or 1 open node :";
   std::cin>>i;
   while(true)
   {
   std::cout<<"Enter number of sides\n";
   std::cin>>n;
   if((n==0)||(n==1)||(n==2))  //since polygon of side 0,1,2 isnt possible
      continue;
   else
      break;
   }
   switch(sel[i])
   {
       case 1: // polygon
       if(eo(n)==2)  // even case
       {
         std::cout<<"Min number of colors is 2\n";    
       }
       else if(eo(n)==1)
       {
         std::cout<<"Min number of colors is 3\n";
       }
       break;
       
       case 2:
       std::cout<<"Min number of colors is 2\n";
       break;
   }
}
       
    
   

