#include<stdio.h>
int main()
{
   struct math
   {
      char polygon[20];
      int sides;
   };
   
   struct math p4={"Sqaure",4};
   struct math p5={"Pentagon",5};
   struct math p6={"Hexagon",6};

   struct math *p;
   p=&p4;
   printf("%d %s\n",p->sides,p->polygon);
      
}
