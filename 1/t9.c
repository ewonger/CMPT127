#include <stdio.h>
#include <math.h>

int main(void)
{
  int i, k, j, x, y, z;

  while(scanf("%d %d %d", &x, &y, &z)!=EOF)
  {
    for (i=z-1;i>=0;i--)
    {
      int left = floor( i * (x/(2.0*z)) );
      int right = ceil( (x-1) + -i * (x/(2.0*z)) );

      for (k=0;k<left;k++)
      {
        printf(" ");
      }
      for (j=left;j<=right;j++)
      {
        if (i==0 || i==z-1)
        {
          printf("#");
        }
        else if (j==left || j==right)
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
