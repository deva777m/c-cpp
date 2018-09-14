#include<iostream>

int main()   // tails = true , heads = false
{

   int n,q;
   std::cin>>n>>q;
   bool coin[n];
   bool tails = true;
   bool heads = false;
   for(int i=0;i<n;i++)
      coin[i] = tails;
   
   while(q--)
   {
      int a,b;
      bool num;
      int count=0;

      std::cin>>num>>a>>b;

      if(num==0)
         for(int i=a;i<=b;i++)
         {  
             if(coin[i]==tails)
                coin[i] = (!tails);
             else
                coin[i] = (!heads);
         }

      else
      {
         
         for(int i=a;i<=b;i++)
            if(coin[i]==heads)
               count++;
         std::cout<<count<<"\n";
      }
   }
     
}
