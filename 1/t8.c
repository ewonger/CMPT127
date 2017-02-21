#include <stdio.h>

int main( void )
{
  int x, y, z, i, j;

  while (scanf("%d %d %d", &x,&y,&z)!=EOF)
  {
    for (i=0;i<y;i++)
    {
      for (j=0;j<x;j++)
      {
        if (i==0 || i==y-1)
        {
          printf("#");
        }
        else if (j==0 || j==x-1)
        {
          printf("#");
        }
        else
        {
          printf(".");
        }
      }
      printf("\n");
    }
  }
  return 0;
}
