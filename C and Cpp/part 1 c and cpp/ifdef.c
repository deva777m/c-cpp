#include<stdio.h>
#define PRINT
int main()
{
  #ifdef PRINT
    printf("hi\n");
    printf("there\n");
    printf("asshole\n");
  #endif

printf("t\n");
}
 
