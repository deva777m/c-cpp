#include<iostream>
int binarysearch(int *array,int min,int max,int target)
{
   int center; 
   while(true)  //doesnt work since if a number doesnt exsist min or max will we greater than max or min resp.
   {
   center = (min+max)/2;
   if(target<(array[center]))
   {   
      max=center-1;
      continue;
   } 
   else if(target>(*(array+center)))
   { 
     min=center+1;
     continue;
   }
   else if(target==(*(array+center)))
       return center;
   else 
       return -1;
   }
}
int main()
{            //0,1,2,3,4 ,5 ,6 ,7 
   int array[]{3,4,5,9,10,12,14,19};
   const int numvals = 8;
   int testvals[numvals]{5,23,4,78,9,8,19};
   int expexvals[numvals]{2,-1,1,-1,3,-1,7};
   for(int i=0;i<numvals;i++)
   {  
     int index=binarysearch(array,0,7,testvals[i]);
     if(index==expexvals[i])
        std::cout<<"Test value "<<testvals[i]<<" passed\n";
     else
        std::cout<<"Test value "<<testvals[i]<<" failed\n";
       
   }
}    
