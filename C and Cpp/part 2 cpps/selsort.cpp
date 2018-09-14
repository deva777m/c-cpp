#include<iostream>
#include<algorithm>
int main() //{3,5,2,1,4,8} //2,5,3,1,4,8  
{
   int a[6]{3,5,2,1,4,8};
   for(int i=0;i<=4;i++)
   {
     int k=i;  //so that we can manipulate i in for2 without changing its value in for1
     for(int j=k+1;j<=5;j++) //for2 for fixing 1st element and comparing with rest of them
     {
       if(a[j]<a[k]) // if this then start comparing from the index which we found smaller than first index 
       {             //this way we find the smallest and swap it with 1st element  
          k=j;       //then we repeat the procedure for remaining values ignoring the first.
       }
     }
     std::swap(a[k],a[i]);
   }  
   for(int p=0;p<=5;p++)
    std::cout<<a[p]<<" ";  
}
