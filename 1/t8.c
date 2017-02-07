#include <stdio.h>

int main( void )
{
  int i=0, x=0, y=0, z=0;

  while (scanf("%d %d %d", &x,&y,&z)!=EOF)
  {
    if (x,y==1)
    {
      printf("#\n");
    }
    else
    {
      for (i=0;i<x;i++)
      {
        printf("#");
      }
      printf("\n");

      for (i=0;i<(y-2);i++)
      {
        printf("#");
        for (j=0;j<(x-2);j++)
        {
          printf(".");
        }
        printf("#");
        printf("\n");
      }
      for (i=0;i<x;i++)
      {
        printf("#");
      }
      printf("\n");
    }
  }
  return 0;
}
