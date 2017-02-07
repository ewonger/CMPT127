#include <stdio.h>
#include <math.h>

int main( void )
{
  float i = 0, largerv = -100000, smallerv = 100000, nums = 0, count = 0;
  float result, avg;

  while( scanf( "%f",&i )!=EOF )
  {
    if( i >= largerv )
    {
      largerv = i;
    }
    if( i <= smallerv )
    {
      smallerv = i;
    }
    nums += i;
    count ++;
  }
  avg = nums/count;
  printf( "%.2f ", smallerv );
  printf( "%.2f ", largerv );
  printf( "%.2f\n", avg );
  return 0;
}
