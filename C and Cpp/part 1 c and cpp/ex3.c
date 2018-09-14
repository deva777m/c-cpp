#include<stdio.h>
void cap(char *s);
int main()
{
  int i;
  char *p;
  printf("Enter the String name: ");
  scanf("%s",p);
  cap(p);
}

void cap(char *s)
{
  int a=0;
  while(*(s+a)!='\0')
  {
    *(s+a)=*(s+a)-32;
     a++;
  }
  printf("%s",s);
}  
 
