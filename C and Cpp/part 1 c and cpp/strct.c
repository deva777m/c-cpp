#include<stdio.h>
#pragma pack(1) 
struct emp
{
   char a;
   int b;
   float s;
};
#pragma pack()
int main()
{
   int ab;
   struct emp b;
   printf("%p %p %p\n",&b.a,&b.b,&b.s);
   printf("%ld\n",sizeof(b.a));
}
