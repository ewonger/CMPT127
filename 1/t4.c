#include <stdio.h>
#include <math.h>

int main( void )
{
   float i = 0;

   int result=scanf( "%f", &i );

   if( result==0 )
   {
     printf( "scanf error: (%d)\n", result);
   }
   else
   {
     printf( "%.0f ", floor(i) );
     printf( "%.0f ", round(i) );
    printf( "%.0f\n", ceil (i) );
  }
   return 0;
}
