#include<stdio.h>
#include<string.h>
void cap(char *s);
int main()
{
  int i;
  char p[i];
  printf("Enter the String name: ");
  gets(p);
  printf("%s\n",p);
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
  printf("%s\n",s);
}  
 
