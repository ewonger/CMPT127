#include <stdlib.h>
#include <stdio.h>

int main( void )
{
  int ch, word=0, last;
  long unsigned int charcount=0, wordcount=0, linecount=0;

  while (EOF != (ch=getchar()))
  {
    charcount++;
    if ((ch>=65 && ch<=90) || (ch>=97 && ch<=122) || (ch==39))
    {
      word=1;
    }
    else
    {
      word=0;
    }
    if (last==1 && word==0)
    {
      wordcount++;
    }
    last=word;
    if (ch=='\n')
    {
      linecount++;
    }
  }
  printf("%lu %lu %lu\n", charcount, wordcount, linecount );
  return 0;
}
