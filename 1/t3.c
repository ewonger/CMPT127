#include <stdio.h>
#include <math.h>

int main( void )
{
   float i = 0;

   printf( "Enter a floating point value: ");

   scanf( "%f", &i );
   printf( "%.0f ", floor(i) );
   printf( "%.0f ", round(i) );
   printf( "%.0f\n", ceil (i) );
   return 0;
}
