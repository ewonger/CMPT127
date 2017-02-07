#include <stdio.h>

int main( void )
{
  int x=0, i=0;

  while(scanf( "%d", &x)!=EOF )
  {
    for( i=0;i<x;i++)
    {
      printf("#");
    }
    printf("\n");
  }

return 0;
}
