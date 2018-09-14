#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  char *p[6];
  char n[50];
  int i,len;
  for(i=0;i<=5;i++)
  {
    scanf("%s",n);
    len=strlen(n);
    p[i]=(char *)malloc(len+1);
    strcpy(p[i],n);
  }
  for(i=0;i<=5;i++)
     printf("%s\n",p[i]);
return 0;
}

