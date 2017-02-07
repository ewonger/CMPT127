#include <stdio.h>
#include <math.h>

int main( void )
{
  float i = 0;

  while (scanf("%f",&i)!=EOF )
  {
      printf( "%.0f ", floor(i) );
      printf( "%.0f ", round(i) );
      printf( "%.0f\n", ceil (i) );
  }
  printf( "Done.\n");
  return 0;
}
