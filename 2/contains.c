#include <string.h>
#include <stdio.h>
#include <stdlib.h> // for atoi() and friends

// takes two arguments: an integer followed by a float
int main( int argc, char* argv[] )
{
  int i, k=0, j=0;

  if( argc != 3 ) // yes 3! argv[0] is the program name
  {
     printf( "I wanted 2 arguments\n" );
  }

  int len1 = strlen( argv[1] );
  int len2 = strlen( argv[2] );
  int count=0;

  for (i=0;i<len1;i++)
  {
    if (argv[1][i]==argv[2][k])
    {
      count++;
      k++;
    }
  }

  if(count!=len2)
    {
      printf("false\n");
    }
  else
    {
      printf("true\n");
    }

  return 0;
}
