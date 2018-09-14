#include<iostream>
int binarysearch(int *array,int min,int max,int target)
{
   int center; 
   while(max>=min)
   {
   center = (min+max)/2;
   if(target<(array[center]))
   {   
      max=center-1;
   } 
   else if(target>(*(array+center)))
   { 
     min=center+1;
   }
   else 
     return center;
   }
   
return -1;
}
int main()
{            //0,1,2,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10,11,12,13,14
   int array[]{3,6,8,12,14,17,20,21,26,32,36,37,42,44,48};
   const int numvals = 9;
   int testvals[numvals]{0,3,12,13,22,26,43,44,49};
   int expexvals[numvals]{-1,0,3,-1,-1,8,-1,13,-1};
   for(int i=0;i<numvals;i++)
   {  
     int index=binarysearch(array,0,14,testvals[i]);
     if(index==expexvals[i])
        std::cout<<"Test value "<<testvals[i]<<" passed\n";
     else
        std::cout<<"Test value "<<testvals[i]<<" failed\n";
       
   }
}    
