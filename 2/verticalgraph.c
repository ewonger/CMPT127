#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  int num=0,i=0,n=0,max=0,k=0,count;
  unsigned int Arr[80]={0};

  while (scanf("%d",&num)!=EOF)
  {
    Arr[i]=num;
    if (num>=max)
    {
      max=num;
    }
    ++i;
  }
  count=max;
  for (n=max-1;n>=0;n--)
  {
    for (k=0;k<i;k++)
    {
      if (Arr[k]>count)
      {
        printf("#");
      }
      else
      {
        printf(" ");
      }
    }
    count--;
    printf("\n");
  }
  for (n=0;n<i;n++)
  {
    if (Arr[n]>0)
    {
      printf("#");
    }
    else
    {
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}
