#include<iostream>
void swap(int &x,int &y){
    
    int temp;
    temp=x;
    x=y;
    y=temp;
}

int sort(int *a,const int n)
{
     for(int i=0;i<n;i++){
        int k=i;
        for(int j=k+1;j<n;j++){
            if(a[k]>a[j]){
                k=j;
            }
        }
        swap(a[k],a[i]);
    }
    for(int i=0;i<n;i++){
        return a[i];
    }
    
}

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
{  
   int n;               // 0 1 1 2 2 3 3
   int a[100000];      // 1 2 3 4 5 6 7
   a[0]=0;
   std::cin>>n;
   for(int i=1;i<n;i++){
       std::cin>>a[i];
   }
   for(int i=0;i<n;i++){
    a[i]=sort(a,n);   
   }
    
   int testvals[n-1];
       for(int i=1;i<n;i++){
           testvals[i]=i ;      
   }
   for(int i=0;i<n;i++)
   {  
     int index=binarysearch(a,0,n,testvals[i]);
     if(index==(-1))
        std::cout<<testvals[i]<<"\n";
   }
}    
