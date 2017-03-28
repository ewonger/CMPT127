#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i=0,n=0,letter=97;
  int ch;
  float freq=0,count=0;
  char tempArr[1000000]={0};
  while (EOF != (ch=getchar()))
  {
    if (ch>=65 && ch<=90)
    {
      tempArr[i]=ch+32;
      ++i;
    }
    if (ch>=97 && ch<=122)
    {
      tempArr[i]=ch;
      ++i;
    }
  }
  for (letter=97;letter<=122;letter++)
  {
    count=0;
    for (n=0;n<i;n++)
    {
      if (letter==tempArr[n])
      {
        count++;
      }
    }
    if (count!=0)
    {
      freq=count/i;
      printf( "%c %.4f\n", letter, freq);
    }
  }
  return 0;
}
