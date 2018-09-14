#include<string.h>
#include<stdio.h>
void join(char *s1,char *s2)
{
   int i,j;
   char p[20];
   for(i=0;i<=strlen(s1)-1;i++)
     {
       p[i]=*s1   
       s1++;
     }
   for(j=1;j<=strlen(s2);j++)
     {
       p[j+strlen(s1)]=*s2;
       s2++;
     }
    printf("%s\n",p);
}

int main()
{
  char source1[20];
  scanf("%s",source1);
  char source2[20];
  scanf("%s",source2);
  join(source1,source2);
}

